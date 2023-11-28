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

ll findIndex(ll n) {

    if(n==1) return 1;
    if(n==2) return 3;
    if(n==3) return 4;

    double phi = (1ll + sqrt(5ll)) / 2ll;
    ll index = round(log(n * sqrt(5ll) + 0.5) / log(phi));
    ll fib = round((pow(phi, index) - pow(1ll - phi, index)) / sqrt(5ll));
    if (fib == n)
        return index;
    else
        return -1; // n is not a Fibonacci number
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll n{};
    cin>>n;
    ll index = findIndex(n);
    cout<<index<<endl;
    
    return 0;
}