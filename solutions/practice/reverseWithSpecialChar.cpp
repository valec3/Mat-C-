#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    string reverseWithSpacesIntact (string s){
        int n = s.length();
        string ans = "";
        // Remove spaces from the end
        for(int i=n-1;i>=0;i--){
            if(!isalpha(s[i])){
                ans += s[i];
            }
        }
        int m = ans.length();
        for(int i=0;i<n;i++){
            if(!isalpha(s[i])){
                string c = string(1, s[i]);
                ans.insert(i,c);
            }
        }
        return ans;
    }    

};