// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        vector<vector<bool>>dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(p[j] == '?' || p[j] == s[i]){
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else{
                    if(p[j] == '*'){
                        dp[i + 1][j + 1] = dp[i + 1][j] | dp[i][j] | dp[i][j + 1];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};