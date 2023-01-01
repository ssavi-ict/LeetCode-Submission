// https://leetcode.com/problems/coin-change

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);
        dp[0] = 0;
        for(int i=0; i<=amount; i++){
            int mValue = 99999;
            for(int j=0; j<coins.size(); j++){
                if(i >= coins[j]){
                    int get = i - coins[j];
                    if(dp[get]!=-1){
                        mValue = min(mValue, dp[get]+1);
                    }
                }
            }
            dp[i] = mValue;
            if(!i) dp[i] = 0;
        }
        return (dp[amount]==99999)?-1:dp[amount];
    }
};