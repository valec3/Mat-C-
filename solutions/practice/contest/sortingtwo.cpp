#include<bits/stc++.h>
using namespace std;
int main(){
    int t{};
    cin>>t;
    while (t--)
    {
        int n{},int *numeros;
        int mapa[21]{};
        cin>>n;
        numeros = new int[n] ;
        for (int i = 0; i < n; i++)
        {
            cin>>numeros[i];
        }
        for (int i = 0; i < n-1; i++)
        {
            if (numeros[i]>numeros[i+1])
            {
                mapa[i]++;
            }
            
        }
        
        delete [] numeros;
    }
    
}