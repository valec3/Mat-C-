#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string reverseWords (string s)
    {
        //code here.
        string ans = "";
        string word = "";
        for(int i = 0; i<s.length(); i++){
            int j = i;
            while(s[i] != '.') j++;
            word = s.substr(i, j - i);
            reverse(word.begin(), word.end());
            ans += word;
            if(i != 0){
                ans += ".";
            }
            i = j;
        }   
        return ans;
    }
};