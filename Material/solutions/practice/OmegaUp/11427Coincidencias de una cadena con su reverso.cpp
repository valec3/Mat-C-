#include<bits/stdc++.h>

using namespace std;

int main(){

    string s{};
    cin>>s;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    int count{};
    for(int i=0;i<s.size();i++){
        if(s[i]== s[s.size()-1-i]) count++;
    }
    cout<<count<<endl;
    return 0;
}