#include<bits/stdc++.h>
using namespace std;

void reverseSubArray(int arr, int n, int l, int r) {
    int temp{};
    for (int i = l; i <= r; i++)
    {
        temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
        r--;
    }
}
int main(){
    int n{7},R{2},L{4};
    int a[n]={1, 2, 3, 4, 5, 6, 7};
    reverseSubArray(a,n,L,R);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;

}