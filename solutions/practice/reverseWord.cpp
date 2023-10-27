// reverse the string without reversing its individual words
#include<bits/stdc++.h>
using namespace std;
string reverseString(string str){
    int n = str.length();
    for (int i = 0; i < n/2; i++)
    {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
    return str;
}
string reverseWordsss(string S){
    vector<string> words;
    int n = S.length();
    for (int i = 0; i < n; i++)
    {
        int j{};
        if (S[i] == '.')
        {
            j = i;
            // revert each word
            string word = reverseString(S.substr(0,i));
            words.push_back(word);
        }
    }
    // revert words
    for (int i = 0; i < words.size(); i++)
    {
        string temp = words[i];
        words[i] = words[n-i-1];
        words[n-i-1] = temp;
    }
    for (size_t i = 0; i < words.size(); i++)
    {
        if (i < words.size()-1)
        {
            S = S + words[i]+'.';
        }else{
            S = S + words[i];
        }
    }
    
    return S;
}

string reverseWords(string s){ 
        int n = s.length();
        vector<string> words;
        for(int i=0;i<n;i++){
            int j = i;
            while(s[j]!='.' && j<n) j++;
            int k = j-1;
            while(i<k){
                char temp = s[i];
                s[i] = s[k];
                s[k] = temp;
                i++;
                k--;
            }
            i = j;
        }
        return s;
} 
string reverseWord(string S){
    string salida{};
    int n = S.length();
    vector<string> words;
    for(int i=0;i<n;i++){
        int j = i;
        while(S[j]!='.' && j<n) j++;
        int k = j-1;
        while(i<k){
            char temp = S[i];
            S[i] = S[k];
            S[k] = temp;
            i++;
            k--;
        }
        i = j;
    }

    for(int i= 0;i<words.size()/2;i++){
        string temp = words[i];
        words[i] = words[words.size()-i-1];
        words[words.size()-i-1] = temp;
    }
    for (int i = 0; i < words.size(); i++)
    {
        if (i < words.size()-1)
        {
            salida = salida + words[i]+'.';
        }else{
            salida = salida + words[i];
        }
    }
    return salida;
}

int main(){
    string s{};
    getline(cin,s);
    s = revertStringWithSeparate(s);
    cout<<s<<endl;
    return 0;
}