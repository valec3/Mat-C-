// Given an array A of n elements, rearrange the array according to the following relations :
// A[i] >= A[i-1], if i is even.
// A[i] <= A[i-1], if i is odd.[Considering 1-indexed array]
// Return the resultant array.


#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<int> assign(int a[], int n){
            vector<int> ans(n,0);
            int evenIdx = 0, oddIdx = n - 1;
            sort(a, a + n);
            
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    ans[i] = a[evenIdx];
                    evenIdx++;
                } else {
                    ans[i] = a[oddIdx];
                    oddIdx--;
                }
            }

            return ans;
            
        }
};