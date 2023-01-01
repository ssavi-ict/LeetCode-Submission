// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    int dp[601][101][101];
    int zeroes[601], ones[601];
    
    int solve(int pos, int zero, int one, int m, int n, int sz){
        if(pos >= sz) return 0;
        if(dp[pos][zero][one]!=-1) return dp[pos][zero][one];
        int mxV = 0;
        if(zero+zeroes[pos] <= m && one+ones[pos]<=n){
            mxV = max(mxV, 1+solve(pos+1, zeroes[pos]+zero, ones[pos]+one, m, n, sz));
        }
        mxV = max(mxV, solve(pos+1, zero, one, m, n, sz));
        return (dp[pos][zero][one] = mxV);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<strs.size(); i++){
            for(int j=0; j<strs[i].size(); j++){
                if(strs[i][j] == '0') zeroes[i]++;
                else ones[i]++;
            }
        }
        
        return solve(0, 0, 0, m, n, strs.size());
    }
};