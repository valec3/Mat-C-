#include<bits/stdc++.h>
using namespace std;

vector<int> findSubarray(int arr[], int n) {
    int start = -1;    // Inicio del subarreglo máximo
    int maxSum = 0;     // Suma máxima encontrada
    int currentSum = 0; // Suma actual
    int maxStart = -1;  // Inicio del subarreglo con suma máxima
    int maxEnd = -1;    // Fin del subarreglo con suma máxima

    for (int i = 0; i < n; i++) {

		// si la suma actual es 0, entonces el inicio del subarreglo es i
        if (currentSum == 0) {
            start = i;
        }

        currentSum += arr[i];

        if (currentSum > maxSum && arr[i] > 0) {
            maxStart = start;
            maxEnd = i;
            maxSum = currentSum;
        } else if (arr[i] > 0 && currentSum == maxSum && (i - start) > (maxEnd - maxStart)) {
			// Si la suma actual es igual a la suma máxima, entonces se verifica si el tamaño 
			// del subarreglo actual es mayor al tamaño del subarreglo máximo
            maxStart = start;
            maxEnd = i;
        }

        if (arr[i] < 0) {
			// Reiniciar la suma actual si el elemento actual es negativo
            currentSum = 0;
        }
    }

    vector<int> result;
    
    if (maxStart == -1 || maxEnd == -1) {
        return result;
    }

    for (int i = maxStart; i <= maxEnd; i++) {
        result.push_back(arr[i]);
    }

    return result;
}

int main() {
    // 1 3 2 -1 2 3 1
    int a[] = {1, 3,2,-1,2,3,1};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v = findSubarray(a, n);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}