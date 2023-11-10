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