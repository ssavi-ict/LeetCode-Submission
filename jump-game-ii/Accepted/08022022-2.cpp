class Solution {
public:

    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int>dp(n+1, 0);

        for(int i=n-1; i>=0; i--){
            int ans = n;
            for(int j=1; j<=nums[i]; j++){
                if(i + j >= n-1){
                    ans = 1;
                    break;
                }
                ans = min(ans, 1 + dp[i + j]);
            }
            dp[i] = ans;
        }

        // return solve(0, n, nums, dp);
        return dp[0];
    }
};