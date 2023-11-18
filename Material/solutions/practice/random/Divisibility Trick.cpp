#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n{};
        string ans{};
        cin>>n;
        for (int i = 0; i <n; i++)
        {
            ans+=to_string(n);
        }
        
        cout<<stoi(ans)<<endl;
    }
    return 0;
}