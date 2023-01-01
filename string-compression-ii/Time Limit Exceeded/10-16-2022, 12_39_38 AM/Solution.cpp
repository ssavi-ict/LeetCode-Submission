// https://leetcode.com/problems/string-compression-ii

class Solution {
public:
    int solve(int pos, string & s, int k, int len, int ch, vector<vector<vector<vector<int>>>> & dp){
        // cout<<pos<<' '<<k<<' '<<len<<' '<<ch<<endl;
        if(k < 0) return 101;
        if(pos >= s.size()) return 0;
        
        // if(k==0) return 0;
        if(dp[pos][ch][len][k] != -1) return dp[pos][ch][len][k];
        
        
        int ret = 101;
        int int_ch = s[pos] - 'a';
        
        // cout<<"a "<<pos<<' '<<k<<' '<<len<<' '<<ch<<endl;
        
        if(ch == int_ch){
            int sentinel = (len == 1) || (len == 9) || (len == 99);
            ret = min(ret, sentinel + solve(pos+1, s, k, len+1, ch, dp));
        }
        else{
            // int compress = get_compressed(len);
            ret = min(ret, 1 + solve(pos+1, s, k, 1, int_ch, dp));
            ret = min(ret, solve(pos+1, s, k-1, len, ch, dp));
        }
        return (dp[pos][ch][len][k] = ret);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<vector<vector<int>>>>dp(n+1, vector<vector<vector<int>>>(27, vector<vector<int>>(n+1, vector<int>(k+1, -1))));
        return solve(0, s, k, 0, 26, dp);
    }
};


