class Solution {
public:

    int solve(int pos, int n, vector<int> & nums, vector<int> & dp){
        if(pos >= n-1) return 0;
        // cout<<pos<<endl;
        if(dp[pos] != -1) return dp[pos];
        int ans = n;
        for(int j=1; j<=nums[pos]; j++){
            ans = min(ans, 1 + solve(pos+j, n, nums, dp));
        }
        return (dp[pos] = ans);
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(0, n, nums, dp);
    }
};