// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
        bool dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            dp[i][1] = true; ans++;
        }
        
        for(int i=0; i<s.size()-1; i++){
            dp[i][2] = (s[i] == s[i+1]);
            if(dp[i][2]){
                ans++;
            }
        }
        // cout<<ans<<endl;
        
        for(int i=3; i<=s.size(); i++){
            for(int j=0; j<=s.size()-i; j++){
                int len = i - 2;
                if(s[j] == s[j+i-1] && dp[j+1][len]){
                    dp[j][i] = true;
                    ans++;
                }
            }
        }
        return ans;
        
    }
};