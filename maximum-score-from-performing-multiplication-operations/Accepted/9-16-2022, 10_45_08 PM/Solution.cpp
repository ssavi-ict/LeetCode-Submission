// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations

class Solution {
public:
    
    /*int solve(int index, int left, int right, vector<int>&nums, vector<int>&multipliers, vector<vector<int>>&dp){
        if(index >= multipliers.size()) return 0;
        if(dp[index][left] != INT_MIN) return dp[index][left];
        int leftSum = (nums[left] * multipliers[index]) + solve(index+1, left+1, right, nums, multipliers, dp);
        int rightSum = (nums[right] * multipliers[index]) + solve(index+1, left, right-1, nums, multipliers, dp);
        dp[index][left] = max(leftSum, rightSum);
        return dp[index][left];
    }*/
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector< vector<int> >dp(m+1, vector<int>(m+1, 0));
        
        for(int index =  m-1; index >= 0; index--){
            int right = nums.size() - 1;
            for(int left = index; left>=0; left--){
                int leftSum = (nums[left] * multipliers[index]) + dp[index+1][left+1];
                int rightSum = (nums[right] * multipliers[index]) + dp[index+1][left]; 
                dp[index][left] = max(leftSum, rightSum);
                right--;
            }
        }
        return dp[0][0];
    }
};