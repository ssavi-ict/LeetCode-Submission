// https://leetcode.com/problems/count-vowels-permutation

class Solution {
public:
    
    int dp[20005][5];
    const int M = 1e9 + 7;
    
    int solve(int pos, int ch_id, int n){
        if(pos == n-1) return 1;
        if(dp[pos][ch_id]!=0) return dp[pos][ch_id];
        int ret = 0;
        if(ch_id == 0){
            ret = (ret%M + solve(pos+1, 1, n)%M)%M;
        }
        else if(ch_id == 1){
            ret = (ret%M + solve(pos+1, 0, n)%M)%M;
            ret = (ret%M + solve(pos+1, 2, n)%M)%M;
        }
        else if(ch_id == 2){
            ret = (ret%M + solve(pos+1, 0, n)%M)%M;
            ret = (ret%M + solve(pos+1, 1, n)%M)%M;
            ret = (ret%M + solve(pos+1, 3, n)%M)%M;
            ret = (ret%M + solve(pos+1, 4, n)%M)%M;
        }
        else if(ch_id == 3){
            ret = (ret%M + solve(pos+1, 2, n)%M)%M;
            ret = (ret%M + solve(pos+1, 4, n)%M)%M;
        }
        else{
            ret = (ret%M + solve(pos+1, 0, n)%M)%M;
        }
        dp[pos][ch_id] = ret;
        return dp[pos][ch_id];
    }
    
    int countVowelPermutation(int n) {
        // memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i=0; i<5; i++){
            ans = (ans%M + solve(0, i, n)%M)%M;
        }
        return ans;
    }
};