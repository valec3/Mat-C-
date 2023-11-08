#include<bits/stdc++.h>
using namespace std;

void pushZerosToEnd(int arr[], int n) {
    int countZero = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            countZero++;
        } else {
            arr[i - countZero] = arr[i];
        }
    }
    for(int i = n - countZero; i < n; i++) {
        arr[i] = 0;
    }
    return arr;
}
int main(){
    int Arr[] = {2, 3, 4, 5, 1, 0, 0, 0, 15}
    int N = size(Arr)/size(Arr[0]);
}