#include<bits/stdc++.h>
using namespace std;

long long pairWithMaxSum(long long arr[], long long N)
    {
        long long maxSum {};
        long long currentSum {};
        for (int i = 0; i < N-1; i++)
        {
            currentSum = arr[i] + arr[i+1];
            if(currentSum > maxSum){
                maxSum = currentSum;
            }
        }
        
        return maxSum;
}

int main() {
    long long a[] = {1, 3,2,-1,2,3,1};
    int n = sizeof(a) / sizeof(a[0]);
    long long sum= pairWithMaxSum(a,n);
    cout<<sum<<endl;
    return 0;
}