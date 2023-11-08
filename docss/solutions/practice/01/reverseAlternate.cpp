#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

string reverseAlternate(string s)
{
    int wordsCount = 0;
    int n = s.length();
    for(int i=0;i<n;i++){
        int j = i;
        while(s[j]!=' ' && j<n) {
            j++;
        }
        wordsCount++;
        int k = j-1;
        while(i<k && wordsCount%2==0){
            char temp = s[i];
            s[i] = s[k];
            s[k] = temp;
            i++;
            k--;
        }
        i = j;
        // cout<<wordsCount<<endl;
    }
    return s;
}
