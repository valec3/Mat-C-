#include<bits/stdc++.h>
using namespace std;

int main(){
    int n{};
    int ans{};
    int maxFrec=0;
    int minFrec{INT_MAX};
    map<int,int> dadosFrec={
        {1,0},
        {2,0},
        {3,0},
        {4,0},
        {5,0},
        {6,0}
    };
    cin>>n;
    for(int i{};i<n;i++){
        int x{};
        cin>>x;
        dadosFrec[x]++;
    }
    for(auto x:dadosFrec){
        cout<<x.first<<" "<<x.second<<endl;
        maxFrec=max(maxFrec,x.second);
        minFrec=min(minFrec,x.second);
    }    
    ans=maxFrec-minFrec;
    cout<<ans<<endl;
    
}