#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        // Your code here
        for(int i=0;i<n;i++){
            arr[i]+=(arr[arr[i]]%n)*n;
        }
        for(int i=0;i<n;i++){
            arr[i]/=n;
        }
    }
    void arrange2(long long arr[], int n) {
        long long aux[n];
        for(int i=0;i<n;i++){
            aux[i]=arr[arr[i]];
        }
        for(int i=0;i<n;i++){
            arr[i]=aux[i];
        }
    }
};