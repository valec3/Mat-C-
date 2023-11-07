#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        long long find_multiplication(int a[], int b[], int n, int m)
    {
        long long mult = 0;
        sort(a, a + n);
        sort(b, b + m);
        mult = a[n - 1] * b[0];
        return mult;
    }
};