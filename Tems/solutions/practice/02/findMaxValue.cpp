#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long int findMaxValue(long long int arr[], int n) {
        // function for finding maximum value of arr[j] – arr[i] + arr[l] – arr[k], such that i < j < k < l.
        if (n < 4)
        {
            return -1;
        }
        
        long long int max_1{}, max_2{}, max_3{}, max_4{};
        max_1 = -arr[0];
        max_2 = arr[1] -arr[0];
        max_3 = arr[1]-arr[0]-arr[2];
        max_4 = arr[1]-arr[0]-arr[2]+arr[3];
        for (int i = 0; i < n; i++)
        {
            max_1 = max(max_1, -arr[i-3]);
            max_2 = max(max_2, max_1+arr[i-2]);
            max_3 = max(max_3, max_2-arr[i-1]);
            max_4 = max(max_4, max_3+arr[i]);

        }
        return  max_4;
    }
};
int main(){
    long long int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution s;
    cout<<s.findMaxValue(arr,n);

    return 0;
}