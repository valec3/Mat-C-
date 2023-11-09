#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

	void rearrange(int arr[], int n) {
        // code here
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        int arr[n];
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                pos.push_back(arr[i]);
            }
            else{
                neg.push_back(arr[i]);
            }
        }
        int minSize = min(pos.size(),neg.size());
        for (int i = 0; i < minSize; i++)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        if (pos.size()>neg.size())
        {
            for (int i = minSize; i < pos.size(); i++)
            {
                ans.push_back(pos[i]);
            }
        }
        else if (pos.size()<neg.size())
        {
            for (int i = minSize; i < neg.size(); i++)
            {
                ans.push_back(neg[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i]=ans[i];
        }
	}
};