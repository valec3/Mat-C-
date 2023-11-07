#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> arranged(int a[],int n)
    {
        vector<int> pos, neg, ans;
        for(int i=0;i<n;i++){
            if(a[i]>=0){
                pos.push_back(a[i]);
            }
            else{
                neg.push_back(a[i]);
            }
        }
        int p{},ng{};
        for (int i = 0; i < n; i++)
        {
            if (i%2==0)
            {
                ans.push_back(pos[p++]);
            }else{
                ans.push_back(neg[ng++]);
            }
        }
        return ans;
    }
};