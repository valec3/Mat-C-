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
    bool cards[n];
    for(int i=0;i<n;i++){
        cin>>cards[i];
        if(cards[i]==false && i%2==0) movs0++;
        if(cards[i]==true && i%2==1) movs1++;
    }
    int onesCountIdx[2] = (movs0<movs1) ? {n-movs0,0} : {n-movs1,1};
    int zerosCountIdx[2] = (movs1>movs0) ? {movs1,1} : {movs0,0};
    int chooseIdx[2] = (onesCountIdx[0]>zerosCountIdx[0]) ? {true,onesCountIdx[1]} : {false,zerosCountIdx[1]};
    for(int i=0;i<n;i++){
        if(cards[i]==chooseIdx[0] && i%2==chooseIdx[1]){
            ans++;
        }
    }

    return 0;
}