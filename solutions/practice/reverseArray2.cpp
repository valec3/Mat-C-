#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans = "";
        vector<string> words;
        string word = "";
        for(int i = 0; i < S.length(); i++){
            if(S[i] == '.'){
                words.push_back(word);
                word = "";
            }
            else{
                word += S[i];
            }
        }
        words.push_back(word);
        for(int i = words.size() - 1; i >= 0; i--){
            ans += words[i];
            if(i != 0){
                ans += ".";
            }
        }
        return ans;
    } 
};