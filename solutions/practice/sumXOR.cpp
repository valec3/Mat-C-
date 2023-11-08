#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
        long long int sum = 0; // Initialize result

        // Recorremos los 32 bits de un entero
        for (int i = 0; i < 32; i++) {
            // Contar el número de elementos
            // con el bit i-ésimo activado 
            long long int count = 0;
            for (int j = 0; j < n; j++)
                if ((arr[j] & (1 << i)))
                    count++;

            // Add "count * (n - count) * 2"
            // to the answer
            sum += (1 << i) * count * (n - count);
        }

        return sum;
    }
};


int main(){
    Solution obj;
    int arr[] = {1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << obj.sumXOR(arr, n) << endl;

}