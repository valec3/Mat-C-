#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n{},ans{},min{};
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll x{};
        cin>>x;
        if(i==1)min=x;
        else if(x<min)min=x;
        ans+=x;
    }
    ans-=min;
    cout<<ans<<"\n";
    return 0;
}