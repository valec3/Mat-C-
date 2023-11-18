#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s{};
    cin>>s;
    int ans{};
    for(int i= 0;i<s.length();i++){
        int temp=stoi(s.substr(i,1));
        ans+=temp;
    }
    cout<<ans<<endl;
    return 0;
}