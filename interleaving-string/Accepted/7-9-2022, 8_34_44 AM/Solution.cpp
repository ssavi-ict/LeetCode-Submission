// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    
    int dp[101][101];
    int l1, l2, l3;
    bool solve(string &s1, string &s2, string &s3, int pos1, int pos2, int pos3){
        if (pos3 == 0) return (pos1==0 && pos2==0);
        if (pos1==0 && pos2==0) return (pos3 == 0);
        
        if(dp[pos1][pos2]!=-1) return dp[pos1][pos2];
        
        if(pos1>0 && pos2>0 && pos3>0 && s1[pos1-1]==s3[pos3-1] && s2[pos2-1]==s3[pos3-1]){
            dp[pos1][pos2] = solve(s1, s2, s3, pos1-1, pos2, pos3-1) ||  solve(s1, s2, s3, pos1, pos2-1, pos3-1);
        }
        else if(pos1>0 && pos3>0 && s1[pos1-1]==s3[pos3-1]){
            dp[pos1][pos2] = solve(s1, s2, s3, pos1-1, pos2, pos3-1);
        }
        else if(pos2>0 && pos3>0 && s2[pos2-1]==s3[pos3-1]){
            dp[pos1][pos2] = solve(s1, s2, s3, pos1, pos2-1, pos3-1);
        }
        else{
            dp[pos1][pos2] = false;
        }
        return dp[pos1][pos2];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if (l1 + l2 != l3) return false;
        return solve(s1, s2, s3, l1, l2, l3);
    }
};