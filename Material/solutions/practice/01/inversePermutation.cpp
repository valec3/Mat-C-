#include<bits/stdc++.h>
using namespace std;

vector<int> inversePermutation(int arr[], int size) {
    vector<int> ans(size);
    for(int i=0;i<size;i++){
        ans[arr[i]-1] = i+1;
    }
    return ans;
}
int main(){
    int N = 5
    int Arr[] = {2, 3, 4, 5, 1}
}