// https://leetcode.com/problems/string-compression-ii

int dp[101][27][101][101];

class Solution {
public:
    
    int get_compressed(int num){
        if(num == 0) return 0;
        if(num == 1) return 1;
        if(num < 10) return 2;
        if(num < 100) return 3;
        return 4;
    }
    
    int solve(int pos, string & s, int k, int len, int ch){
        if(k< 0) return 101;
        if(pos >= s.size()) return get_compressed(len);
        if(dp[pos][ch][len][k] != -1) return dp[pos][ch][len][k];
        
        int ret = 101;
        int int_ch = s[pos] - 'a';
        
        ret = min(ret, solve(pos+1, s, k-1, len, ch));
        if(ch == int_ch){
            ret = min(ret, solve(pos+1, s, k, len+1, ch));
        }
        else{
            int compress = get_compressed(len);
            ret = min(ret, compress + solve(pos+1, s, k, 1, int_ch));
        }
        return (dp[pos][ch][len][k] = ret);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, s, k, 0, 0);
    }
};