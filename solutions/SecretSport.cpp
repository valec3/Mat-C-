#include<bits/stdc++.h>
using namespace std;
int main(){
    int op[3] = {'A','B','?'};
    int t{};
    cin>>t;
    while(t--){
        int n{0};
        string s{};
        int countWinner{},countB{};
        cin>>n;
        cin>>s;
        char posibleWinner = s[n-1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-i; j++)
            {
                if (s[i]==posibleWinner){
                    countWinner++;
                }
            }
            
        }

        // pass all test cases
        cout<<posibleWinner<<"\n";
    }
    return 0;
}