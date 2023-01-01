// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    
    int solve(int index, vector<int> &prices, int n, bool buy, int capacity, vector<vector<vector<int>>> & dp){
        if(capacity == 0) return 0;
        if(index == n) return 0;
        
        if(dp[index][buy][capacity]!=-1) return dp[index][buy][capacity];
        
        int ret = 0;
        if(buy){  // We can buy
            ret = max(ret, -prices[index] + solve(index+1, prices, n, 0, capacity, dp));
            ret = max(ret, 0 + solve(index+1, prices, n, 1, capacity, dp));
        }
        else{    // We can sell
            ret = max(ret, prices[index] + solve(index+1, prices, n, 1, capacity-1, dp));
            ret = max(ret, 0 + solve(index+1, prices, n, 0, capacity, dp));
        }
        
        return dp[index][buy][capacity] = ret;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        int ans = solve(0, prices, n, 1, 2, dp);
        return ans;
    }
};