// https://leetcode.com/problems/jump-game-vi

class Solution {
public:
    int solve(vector<int>&dp, int pos, int k, vector<int>&nums){
        // cout<<pos<<endl;
        if(dp[pos]!=INT_MIN) return dp[pos];
        for(int i=1; i<=k; i++){
            if(pos+i>=size(nums)) continue;
            dp[pos] = max(dp[pos], nums[pos]+solve(dp, pos+i, k, nums));
        }
        return dp[pos];
    }
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n+5, INT_MIN);
        dp[n-1] = nums[n-1];
        return solve(dp, 0, k, nums);
    }
};