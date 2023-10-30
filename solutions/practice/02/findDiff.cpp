#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int findDiff(int arr[], int n) {
        map<int,int>mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int ans=0;
        // max repeat element
        int max=0;
        int min=INT_MAX;
        for(auto i:mp){
            if(i.second>max){
                max=i.second;
            }
            if(i.second<min){
                min=i.second;
            }
        }
        ans=max-min;
        return ans;
    }
    int findDiff2(int arr[], int n) {
        int max = *max_element(arr, arr + n);
        int min = *min_element(arr, arr + n);
        int range = max - min + 1;
        int freq[range];
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; i++) {
            freq[arr[i] - min]++;
        }
        int ans = 0;
        int max_freq = 0;
        int min_freq = INT_MAX;
        for (int i = 0; i < range; i++) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
            }
            if (freq[i] < min_freq && freq[i] != 0) {
                min_freq = freq[i];
            }
        }
        ans = max_freq - min_freq;
        return ans;
    }
};
int main(){

    Solution obj;
    int arr[] = {2, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<obj.findDiff(arr,n);
    return 0;
}