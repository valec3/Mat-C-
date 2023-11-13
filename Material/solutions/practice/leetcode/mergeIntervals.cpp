#include<bits/stdc++.h>
using namespace std;

    
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());

    for(int i = 0; i < n; i++){
        if(ans.empty() || ans.back()[1] < intervals[i][0]){
            ans.push_back(intervals[i]);
        }
        else if (intervals[i][0] <= ans.back()[1])
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        
    }
    return ans;        
}