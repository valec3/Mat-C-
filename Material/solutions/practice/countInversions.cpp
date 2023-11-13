#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int ans = 0;
        mergeSort(arr, 0, N-1, ans);
        return ans;
    }
    void mergeSort(long long arr[], long long l, long long r, long long &ans){
        if(l<r){
            long long m = l + (r-l)/2;
            mergeSort(arr, l, m, ans);
            mergeSort(arr, m+1, r, ans);
            merge(arr, l, m, r, ans);
        }
    }
    void merge(long long arr[], long long l, long long m, long long r, long long &ans){
        long long n1 = m-l+1;
        long long n2 = r-m;
        long long L[n1], R[n2];
        for(long long i=0; i<n1; i++) L[i] = arr[l+i];
        for(long long i=0; i<n2; i++) R[i] = arr[m+1+i];
        long long i=0, j=0, k=l;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
                // Si L[i] > R[j], entonces todos los elementos de L[i+1] hasta L[n1-1] son mayores a R[j]
                ans += n1-i;
            }
            k++;
        }
        while(i<n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    


};