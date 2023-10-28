#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int findSum(int A[], int N)
    {
        sort(A, A + N);
        int min = A[0];
        int max = A[N - 1];
        return min + max;
    }

};