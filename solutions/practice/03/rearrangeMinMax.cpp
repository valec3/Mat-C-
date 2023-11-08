#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
        long long aux[n+1];
        for (int i = 0; i < n; i++)
        {
            aux[i] = arr[i];
        }
        sort(aux, aux+n);
        for (int i = 0; i < n; i++)
        {
            if (i%2 == 0)
            {
                arr[i] = aux[n-1-i/2];
            }
            else
            {
                arr[i] = aux[i/2];
            }
        }         
    }
};