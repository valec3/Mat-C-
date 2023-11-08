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
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int b{} //azul
    ,y{}//amarillo
    ,r{};//rojo
    cin>>b>>y>>r;
    
    string s{};
    char c{};
    while(cin>>c){
        if(c=='\n')break;
        s+=c;
    
    }
    
    cout<<s<<endl;
    int countSymbols{},countLetters{},countNumbers{};
    for (int i = 0; i < s.length(); i++)
    {   
        if(isdigit(s[i])){
            countNumbers++;
        }
        else if(isalpha(s[i])){
            countLetters++;
        }
        else{
            countSymbols++;
        }
    }

    // cout<<countNumbers<<" "<<countLetters<<" "<<countSymbols<<endl;

    int counts[3] = {countNumbers,countLetters,countSymbols};
    int maxTintas[3] = {b,y,r};
    sort(counts,counts+3);
    sort(maxTintas,maxTintas+3);
    bool isPossible{true};
    for (int i = 0; i < 3; i++)
    {
        if(counts[i]>maxTintas[i]){
            isPossible = false;
            break;
        }
    }
    cout<<(isPossible?"Yes":"No")<<endl;
    return 0;
}