// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        // int ans = solve(0, prices, 1, k, dp);
        // return ans;
        int n = prices.size();
        
        for(int index=n-1; index>=0; index--){
            for(int capacity = 1; capacity<=k; capacity++){
                for(int buy=0; buy<2; buy++){
                    int ret = 0;
                    if(buy){
                        ret = max(ret, -prices[index] + dp[index+1][0][capacity]);
                        ret = max(ret, 0 + dp[index+1][1][capacity]);
                    }
                    else{
                        ret = max(ret, prices[index] + dp[index+1][1][capacity-1]);
                        ret = max(ret, 0 + dp[index+1][0][capacity]);
                    }
                    dp[index][buy][capacity] = ret;
                }
            }
        }
        // cout<<dp[0][0][k]<<' '<<dp[0][1][k]<<endl;
        return dp[0][1][k];
    }
};