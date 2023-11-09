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
    
    int h{},w{};
    string s{};
    cin>>h>>w;
    vector<vector<int>> v(h,vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        cin>>s;
        for (int j = 0; j < w; j++)
        {
            v[i][j] = s[j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return 0;
}