#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MAXN 1000005
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n{},movs0{},movs1{},ans{};
    cin>>n;
    int cards[n];
    for(int i=0;i<n;i++){
        cin>>cards[i];
        if(cards[i]!=0 && i%2==0) movs0++;
        if(cards[i]!=1 && i%2==1) movs0++;

        if(cards[i]!=1 && i%2==0) movs1++;
        if(cards[i]!=0 && i%2==1) movs1++;
    }
    ans=min(movs0,movs1);
    cout<<ans<<endl;

    return 0;
}