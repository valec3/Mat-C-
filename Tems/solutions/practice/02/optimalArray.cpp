#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        vector<int> operations(n,0);
        for (int i = 1; i < n; i++)
        {
            int valueTarget = abs(a[i] - a[i/2]);
            operations[i]=operations[i-1]+valueTarget;
        }
        return operations;
    }
};
int main(){
    vector<int> a = {1,6,9,12};
    Solution s;
    vector<int> operations = s.optimalArray(4,a);
    for (int i = 0; i < operations.size(); i++)
    {
        cout<<operations[i]<<" ";
    }
    return 0;
}