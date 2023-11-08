#include<bits/stdc++.h>
using namespace std;

pair<long long, long long> getMinMax(long long a[], int n) {
    long long min = a[0], max = a[0];
    sort(a, a + n);
    min = a[0];
    max = a[n - 1];
    return make_pair(min, max);
}