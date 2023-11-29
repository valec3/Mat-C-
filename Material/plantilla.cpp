#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forn(i,a,b) for(int i=a;i<b;i++)
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
    
    int t{};
    cin >> t;
    while(t--){
        int n{};
        cin >> n;
        int a[n];
        forn(i,0,n) cin >> a[i];
        int ans = 0;
        forn(i,0,n-1){
            int mn = min(a[i],a[i+1]);
            int mx = max(a[i],a[i+1]);
            while(mn*2 < mx){
                mn *= 2;
                ans++;
            }
        }
        cout << ans << endl;

    }
    
    return 0;
}