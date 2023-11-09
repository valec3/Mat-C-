#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    void sortIt(long long arr[], long long n)
    {
        vector<int> ans;
        vector<int> odds;
        vector<int> evens;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                evens.push_back(arr[i]);
            }
            else
            {
                odds.push_back(arr[i]);
            }
        }
        sort(odds.begin(), odds.end(), greater<int>());
        sort(evens.begin(), evens.end());
        for (int i = 0; i < odds.size(); i++)
        {
            ans.push_back(odds[i]);
        }
        for (int i = 0; i < evens.size(); i++)
        {
            ans.push_back(evens[i]);
        }
        

        for (int i = 0; i < n; i++)
        {
            arr[i] = ans[i];
        }
    }
};

int main(){
    long long int a[] = {1, 3, 2, 7, 5, 4};
    Solution s;

    s.sortIt(a, 6);
    for(int e:a){
        cout<<e<<" ";
    }
    cout<<endl;
}