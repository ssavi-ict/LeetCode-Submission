// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    
    int solve(int index, vector<int>&prices, int buy, int capacity, vector<vector<vector<int>>> & dp){
        if(capacity == 0) return 0;
        if(index == prices.size()) return 0;
        if(dp[index][buy][capacity]!=-1) return dp[index][buy][capacity];
        
        int ret = 0;
        if(buy){  // Buy
            ret = max(ret, -prices[index]+solve(index+1, prices, 0, capacity, dp));
            ret = max(ret, 0+solve(index+1, prices, 1, capacity, dp));
        }
        else{   // Sell
            ret = max(ret, prices[index]+solve(index+1, prices, 1, capacity-1, dp));
            ret = max(ret, 0 + solve(index+1, prices, 0, capacity, dp));
        }
        return dp[index][buy][capacity] = ret;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        int ans = solve(0, prices, 1, k, dp);
        return ans;
    }
};