// https://leetcode.com/problems/k-inverse-pairs-array

class Solution {
public:
    const int mod = 1000000000 + 7;
    
    int kInversePairs(int n, int k) {
        int dp[n+2][k+2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        
        for(int i=1; i<=n; i++){
            long long sum = 0;
            int kidx = 0;
            for(int j=0; j<=k; j++){
                if(j==0){
                    dp[i][j] = 1;
                    sum += 1;
                }
                else{
                    sum = sum + dp[i-1][j];
                    if(j>=i){
                        sum -= dp[i-1][kidx++];
                    }
                    dp[i][j] = (sum % mod);
                }
            }
        }
        return dp[n][k];
    }
};