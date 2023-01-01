// https://leetcode.com/problems/house-robber

class Solution {
public:

    int solve(vector<int>&nums, int pos, vector<int>&dp, int n){
        if(pos >= n) return 0;
        if(dp[pos] != -1) return dp[pos];
        int maxValue = 0;
        maxValue = max(maxValue, solve(nums, pos + 2, dp, n) + nums[pos]);
        maxValue = max(maxValue, solve(nums, pos + 1, dp, n));
        return (dp[pos] = maxValue);
    }

    int rob(vector<int>& nums) {
        int n = size(nums);
        if(n == 1) return nums[0];
        vector<int>dp(n, -1);
        int ans = solve(nums, 0, dp, n);
        return ans;
    }
};