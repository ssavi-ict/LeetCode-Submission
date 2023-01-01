// https://leetcode.com/problems/coin-change

class Solution {
public:
    
    int solve(vector<int>&coins, int amount, vector<int>&dp){
        if(amount < 0) return 99999;
        if(amount == 0) return 0;
        // cout<<amount<<' '<<idx<<' '<<dp[amount][idx]<<endl;
        if(dp[amount]!=-1) return dp[amount];
        // cout<<amount<<endl;
        int minCount = 99999;
        for(int i=0; i<coins.size(); i++){
            if(coins[i]<=amount){
                minCount = min(minCount, 1+solve(coins, amount-coins[i], dp));
            }
        }
        return (dp[amount] = minCount);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);
        int ret = solve(coins, amount, dp);
        return (ret<99999?ret:-1);
    }
};