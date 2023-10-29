#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int max = arr[0];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }
};

int main(){
    vector<int> arr1{1, 2, 3, 4, 5};
    Solution obj;
    int ans = obj.largest(arr1,5);
    return 0;
}