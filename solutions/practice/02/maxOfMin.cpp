#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(int arr[], int n)
    {
        // Creamos un vector 'ans' de tamaño 'n' con todos los elementos inicializados a 0.
        vector<int> ans(n, 0);
        
        // Creamos una pila 's' para realizar un seguimiento de los índices en 'arr'.
        stack<int> s;
        
        // Creamos dos arrays 'left' y 'right' para almacenar los índices de los elementos a la izquierda
        // y a la derecha de cada elemento en 'arr'.
        int left[n], right[n];
        
        // Inicializamos 'left' con -1 y 'right' con 'n' para marcar los valores
        //  iniciales antes de buscar límites más pequeños.
        for(int i = 0; i < n; i++){
            left[i] = -1;
            right[i] = n;
        }
        
        // Primera pasada desde la izquierda de 'arr' para encontrar
        // los límites más pequeños a la izquierda de cada elemento.
        for(int i = 0; i < n; i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(!s.empty()){
                left[i] = s.top();
            }
            s.push(i);
        }
        
        // Vaciamos la pila 's'.
        while(!s.empty()){
            s.pop();
        }
        
        // Segunda pasada desde la derecha de 'arr' para encontrar los límites más pequeños a la derecha de cada elemento.
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(!s.empty()){
                right[i] = s.top();
            }
            s.push(i);
        }
        
        // Calculamos el máximo de los mínimos de subarrays contiguas y lo almacenamos en 'ans'.
        for(int i = 0; i < n; i++){
            int len = right[i] - left[i] - 1;
            ans[len - 1] = max(ans[len - 1], arr[i]);
        }
        
        // Realizamos otra pasada para asegurarnos de que 'ans' contenga el máximo acumulado en lugar del máximo de los mínimos en cada longitud.
        for(int i = n - 2; i >= 0; i--){
            ans[i] = max(ans[i], ans[i + 1]);
        }
        
        // Devolvemos 'ans', que contiene el resultado final.
        return ans;
    }

};

int main(){
    return 0;
}