#include <bits/stdc++.h>
using namespace std;

string reverseString(string s){
    set <char> letters;
    string ans{};
    reverse(s.begin(),s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (letters.find(s[i])!=letters.end())
        {
            continue;
        }else{
            letters.insert(s[i]);
            ans+=s[i];
        }
    }
    return ans;
}

int main()
{
    string S = "GEEKS FOR GEEKS";
    cout<<reverseString(S)<<endl;
    return 0;
}