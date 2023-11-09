#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int secons{4};
    string s{};
    cin>>s;
    for (int i = 0; i < 3; i++)
    {
        if(s[0]==1){
            seconds-=1;
        }
        seconds += s[i+1]-s[i];
    }
    
    return 0;
}