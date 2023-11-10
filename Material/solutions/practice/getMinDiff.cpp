#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int ans = arr[n-1] - arr[0];
        int small = arr[0] + k;
        int big = (arr[n-1] - k >0 ? arr[n-1] - k : arr[n-1] + k);
        if(small > big) swap(small, big);
        for(int i = 1; i < n-1; i++) {
            int add = arr[i] + k;
            int sub = arr[i] - k;
            if(sub >= small || add <= big){
                continue;
            }
            if(big - sub <= add - small){
                small = sub;
            }
            else{
                big = add;
            }
        }
        cout<<small<<" "<<big<<endl;
        return min(ans, big - small);
    }
};

