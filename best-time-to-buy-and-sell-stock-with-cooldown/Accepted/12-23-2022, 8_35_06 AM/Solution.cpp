// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    
    /*int solve(int index, vector<int>&prices, bool buy, vector<vector<int>>&dp){
        if(index >= size(prices)) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int ret = 0;
        if(buy){
            ret = max(ret, -prices[index] + solve(index + 1, prices, 0, dp));
            ret = max(ret, 0 + solve(index+1, prices, 1, dp));
        }
        else{
            ret = max(ret, prices[index] + solve(index + 2, prices, 1, dp));
            ret = max(ret, 0 + solve(index + 1, prices, 0, dp));
        }
        return dp[index][buy] = ret;
    }*/
    
    int maxProfit(vector<int>& prices) {
        int n = size(prices);
        vector<vector<int>>dp(n+2, vector<int>(2, 0));
        
        for(int index = n-1; index>=0; index--){
            for(int buy=0; buy<2; buy++){
                int ret = 0;
                if(buy){
                    ret = max(ret, -prices[index] + dp[index+1][0]);
                    ret = max(ret, 0 + dp[index+1][1]);
                }
                else{
                    ret = max(ret, prices[index] + dp[index+2][1]);
                    ret = max(ret, 0 + dp[index+1][0]);
                }
                dp[index][buy] = ret;
            }
        }
        return dp[0][1];
    }
};