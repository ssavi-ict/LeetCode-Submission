// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>>curr(2, vector<int>(3,0));
        vector<vector<int>>after(2, vector<int>(3,0));
        
        for(int index=n-1; index>=0; index--){
            for(int capacity=1; capacity<=2; capacity++){
                for(int buy=0; buy<=1; buy++){
                    int ret = 0;
                    if(buy){
                        ret = max(ret, -prices[index] + after[0][capacity]);
                        ret = max(ret, 0 + after[1][capacity]);
                    }
                    else{
                        ret = max(ret, prices[index] + after[1][capacity - 1]);
                        ret = max(ret, 0 + after[0][capacity]);
                    }
                    curr[buy][capacity] = ret;
                }
            }
            after = curr;
        }
        return after[1][2];
    }
};