// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations

class Solution {
public:
    
    int solve(int index, int left, int right, vector<int>&nums, vector<int>&multipliers, vector<vector<int>>&dp){
        if(index == multipliers.size()) return 0;
        if(dp[index][left] != -1) return dp[index][left];
        int leftSum = (nums[left] * multipliers[index]) + solve(index+1, left+1, right, nums, multipliers, dp);
        int rightSum = (nums[right] * multipliers[index]) + solve(index+1, left, right-1, nums, multipliers, dp);
        dp[index][left] = max(leftSum, rightSum);
        return dp[index][left];
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector< vector<int> >dp(m+1, vector<int>(m+1, -1));
        return solve(0, 0, nums.size()-1, nums, multipliers, dp);
    }
};