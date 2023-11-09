#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
        set<int> s;
        vector<int> ans;
        for(int i=0;i<n;i++){
            s.insert(arr1[i]);
            s.insert(arr2[i]);
        }
        // Remove elements from the set until size is 5
        while(s.size()>n){
            s.erase(s.begin());
        }
        // for(auto it=s.begin();it!=s.end();it++){
        //     cout<<*it<<" ";
        // }
        // Add max element to the array
        for (int i = 0; i < n; i++)
        {
            // Exist element into final of the set
            if(s.find(arr2[i])!=s.end()){
                s.erase(arr2[i]);
                ans.push_back(arr2[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(s.find(arr1[i])!=s.end()){
                s.erase(arr1[i]);
                ans.push_back(arr1[i]);
            }
        }
        
        return ans;
    }
};
int main(){
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    Solution obj;
    vector<int> ans = obj.maximizeArray(arr1,arr2,n);
    for(auto it=ans.begin();it!=ans.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}