#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a{},b{};
    cin>>a>>b;
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a/b<<endl;
    cout<<a*b<<endl;
    cout<<static_cast<long long>(pow(2ll,a+b))<<endl;
    return 0;
}