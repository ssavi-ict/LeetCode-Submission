// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    
    string longestPalindrome(string s) {
        int len = s.size();
        bool dp[len+1][len+1];
        int st = -1, mxL = -1;
        memset(dp, false, sizeof(dp));
        for(int i=1; i<=len; i++){
            for(int j=0; j<len; j++){
                if(i==1){
                    dp[j][i] = true, st = j, mxL = i;
                }
                else if(i==2){
                    if(s[j] == s[j+1] && j+1<len){
                        dp[j][i] = true, st = j, mxL = i;
                    }
                }
                else{
                    if(j+i-1<len && s[j]==s[j+i-1] && dp[j+1][i-2]){
                        dp[j][i] = true;
                        if (i > mxL){
                            mxL = i, st = j;
                        }
                    }
                }
            }
        }
        return s.substr(st, mxL);
    }
};