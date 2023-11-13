#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, prices[j]-prices[i]);
            }
        }
        return ans;
    }
    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int minPrice = INT_MAX;
        for(int i=0; i<n; i++){
            minPrice = min(minPrice, prices[i]);
            ans = max(ans, prices[i]-minPrice);
        }
        return ans;
    }
    int maxProfit3(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int minPrice = INT_MAX;
        for(int i=0; i<n; i++){
            if(prices[i]<minPrice) minPrice = prices[i];
            else if(prices[i]-minPrice>ans) ans = prices[i]-minPrice;
        }
        return ans;
    }
};