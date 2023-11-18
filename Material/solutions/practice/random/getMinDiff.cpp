#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int ans = arr[n-1] - arr[0];
        int small = arr[0] + k;
        int big = (arr[n-1] - k >=0 ? arr[n-1] - k : arr[n-1] + k);
        int minOp = 0, maxOp = 0;
        for(int i =1;i<n;i++){
            int op = arr[i-1] + k;
            if (arr[i] < k )
            {
                continue;
            }
            maxOp = max (big, op);
            minOp = min(small, arr[i] - k);
            ans = min(ans, maxOp - minOp); 
        }
        return ans;
    }
};

