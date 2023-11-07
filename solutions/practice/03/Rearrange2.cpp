#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            vector<int> pos;
            vector<int> neg;
            vector<int> ans;
            for(int i=0;i<n;i++){
                if(arr[i]>=0){
                    pos.push_back(arr[i]);
                }
                else{
                    neg.push_back(arr[i]);
                }
            }
            // sort(pos.begin(),pos.end());
            // sort(neg.begin(),neg.end());
            for (int i = 0; i < n; i++)
            {
                if (arr[i]>=0)
                {
                    arr[i]=pos[i];
                }
                else if (arr[i]<0)
                {
                    arr[i]=neg[i];
                }
                
            }
            
        }
};