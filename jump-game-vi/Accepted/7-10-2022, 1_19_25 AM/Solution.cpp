// https://leetcode.com/problems/jump-game-vi

class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n+5, INT_MIN);
        dp[0] = nums[0];
        multiset<int>mSet;
        mSet.insert(dp[0]);
        
        for(int i=1; i<n; i++){
            if(i>k) mSet.erase(mSet.find(dp[i-k-1]));
            dp[i] = max(dp[i], *(--mSet.end()) +nums[i]);
            mSet.insert(dp[i]);
        }
        return dp[n-1];
    }
};