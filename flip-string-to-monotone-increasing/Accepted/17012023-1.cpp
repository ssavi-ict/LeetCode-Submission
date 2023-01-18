class Solution {
public:

    int solve(int pos, int last, string & s, vector<vector<int>> & dp, int n){
        if(pos >= n) return 0;
        if(dp[pos][last] != -1) return dp[pos][last];
        if(last == 1){
            dp[pos][last] = (s[pos] == '0') + solve(pos+1, 1, s, dp, n);
        }
        else{
            dp[pos][last] = (s[pos] == '0') + solve(pos+1, 1, s, dp, n);
            dp[pos][last] = min(dp[pos][last], (s[pos] == '1') + solve(pos+1, 0, s, dp, n));
        }
        return dp[pos][last];
    }

    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return solve(0, 0, s, dp, n);
    }
};