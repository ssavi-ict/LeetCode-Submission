// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar = prices[0], ans = 0;
        for(auto price: prices){
            minsofar = min(minsofar, price);
            ans = max(ans, price-minsofar);
        }
        return ans;
    }
};