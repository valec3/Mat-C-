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
    
    int n{},k{};
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    for(int i=0;i<n;i++){
        if(a[i]==k) {
            cout<<i<<endl;
            return 0;
        }
            
    }
    cout<<"NO"<<endl;
}