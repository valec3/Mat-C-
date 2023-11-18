#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> set;
    int numDuplicate = 0;
    for (int i = 0; i < n; i++) {
        if (set.find(nums[i]) != set.end()) {
            numDuplicate = nums[i];
            break;
        }
        set.insert(nums[i]);
    }
    return numDuplicate;
}
int findDuplicate2(vector<int>&nums){
    int n = nums.size();
    int aux[n+1];
    for(int i = 0; i < n; i++){
        aux[i] = 0;
    }
    for(int i = 0; i < n; i++){
        aux[nums[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(aux[i] > 1){
            return i;
        }
    }
    return -1;
}