class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        for(int pos=n-1; pos>=0; pos--){
            for(int last=1; last>=0; last--){
                if(last == 1){
                    dp[pos][last] = (s[pos] == '0') + dp[pos+1][last];
                }
                else{
                    dp[pos][last] = (s[pos] == '0') + dp[pos+1][1];
                    dp[pos][last] = min(dp[pos][last], (s[pos] == '1') + dp[pos+1][0]);
                }
            }
        }
        return dp[0][0];
    }
};