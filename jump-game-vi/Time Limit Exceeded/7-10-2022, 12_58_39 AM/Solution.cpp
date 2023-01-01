// https://leetcode.com/problems/jump-game-vi

class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n+5, INT_MIN);
        dp[0] = nums[0];
        for(int i=0; i<n; i++){
            for(int j=1; j<=k && j<=i; j++){
                dp[i] = max(dp[i], nums[i] + dp[i - j]);
            }
        }
        return dp[n-1];
    }
};