// https://leetcode.com/problems/string-compression-ii

class Solution {
public:
    
    int get_compressed(int num){
        if(num == 0) return 0;
        if(num == 1) return 1;
        if(num < 10) return 2;
        if(num < 100) return 3;
        return 4;
    }
    
    int solve(int pos, string & s, int k, int len, int ch, vector<vector<vector<vector<int>>>> & dp){
        // cout<<pos<<' '<<k<<' '<<len<<' '<<ch<<endl;
        if(pos >= s.size() || k < 0) return get_compressed(len);
        if(len > s.size()) return 101;
        // if(k==0) return 0;
        if(dp[pos][ch][len][k] != -1) return dp[pos][ch][len][k];
        
        
        int ret = 101;
        int int_ch = s[pos] - 'a';
        
        // cout<<"a "<<pos<<' '<<k<<' '<<len<<' '<<ch<<endl;
        
        if(k > 0) ret = min(ret, solve(pos+1, s, k-1, len, ch, dp));
        if(ch == int_ch){
            ret = min(ret, solve(pos+1, s, k, len+1, ch, dp));
        }
        else{
            int compress = get_compressed(len);
            ret = min(ret, compress + solve(pos+1, s, k, 1, int_ch, dp));
        }
        return (dp[pos][ch][len][k] = ret);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<vector<vector<int>>>>dp(n, vector<vector<vector<int>>>(27, vector<vector<int>>(n+1, vector<int>(k+1, -1))));
        return solve(0, s, k, 0, 0, dp);
    }
};