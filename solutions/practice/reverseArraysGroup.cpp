//Problem 01 : Reverse the array

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void reverseInGroups(vector<long long>& arr, int n, int k){
    for(int i=0;i<n;i+=k){
        int left = i;
        // If the last group is smaller than k
        int right = min(i+k-1,n-1);
        while(left<right){
            swap(arr[left++],arr[right--]);
        }
    }
}

int main(){
    vector<int> arr={1,2,3,4,5}
    reverseInGroups(arr,5,3);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}