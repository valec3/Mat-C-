#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // L and R are input array
    // maxx : maximum in R[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in L[] and R[]
    //Function to find the maximum occurred integer in all ranges.
    int maxOccured(int L[], int R[], int n, int maxx){
        vector<int>v(maxx+1,0);
        for(int i=0; i<n; i++) 
            for(int j=L[i]; j<=R[i]; j++) 
                v[j]++;

        int max=1,ans=0;
        for(int i=0;i<=maxx;i++){
            if(v[i]>max){
                max=v[i];
                ans=i;
            }
        }
        return ans;
    
    }
    int maxOccured2(int L[], int R[], int n, int maxx){
        int *arr = new int[maxx + 2]; // Incrementamos el tamaño en 2 para manejar el valor máximo de R[]
        std::fill(arr, arr + maxx + 2, 0); // Inicializamos el arreglo con 0
        
        // Incrementar las ocurrencias de los números en las posiciones de inicio y disminuir las ocurrencias en las posiciones de fin
        for (int i = 0; i < n; ++i) {
            arr[L[i]]++;
            arr[R[i] + 1]--;
        }

        int maxOccurrence = 0;
        int result = -1;
        int current = 0;

        // Encontrar el número con la máxima ocurrencia
        for (int i = 0; i <= maxx; ++i) {
            current += arr[i];
            if (current > maxOccurrence) {
                maxOccurrence = current;
                result = i;
            }
            // Los numeros 1 haran que podamos ver cuando se intersectan los rangos
            cout<<current<<" ";
        }

        delete[] arr; // Liberamos la memoria del arreglo dinámico

        return result ;
    }
};

int main(){

    Solution obj;
    int L[] = {2, 1, 3};
    int R[] = {5, 4, 9};
    int n = sizeof(L)/sizeof(L[0]);
    int max = obj.maxOccured(L, R, n, 9);
    cout<<max<<endl;
    return 0;
}