// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numTilings(int n) {
        vector<long long>dp(4, 0);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 5;
        if(n < 4) return dp[n-1];

        for(int i=4; i<=n; i++){
            dp[3] = ((dp[2] * 2)%MOD + dp[0])%MOD;
            dp[0] = dp[1], dp[1] = dp[2], dp[2] = dp[3]; 
        }
        return dp[3];
    }
};