// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxsofar = 0, ans = 0;
        for(int i=prices.size()-1; i>=0; i--){
            maxsofar = max(maxsofar, prices[i]);
            ans = max(ans, maxsofar-prices[i]);
        }
        return ans;
    }
};