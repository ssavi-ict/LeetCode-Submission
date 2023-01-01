// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minsofar = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            minsofar = min(minsofar, prices[i]);
            ans = max(ans, prices[i]-minsofar);
        }
        return ans;
    }
};