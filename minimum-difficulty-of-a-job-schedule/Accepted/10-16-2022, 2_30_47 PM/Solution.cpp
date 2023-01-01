// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule

class Solution {
public:

    const int inf = 1e6;

    int solve(int pos, int d, vector<int> & jd, vector<vector<int>> & dp, int len){
        if(pos >= len) return 0;
        if(d <= 0) return inf;
        if(dp[pos][d] != -1) return dp[pos][d];

        int ret = inf;
        int curMax = jd[pos];
        for(int i=pos; i<=len - d; i++){
            curMax = max(curMax, jd[i]);
            ret = min(ret, curMax + solve(i+1, d-1, jd, dp, len));
        }
        return (dp[pos][d] = ret);
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;
        vector<vector<int>>dp(n+1, vector<int>(d+1, -1));
        int ans = solve(0, d, jobDifficulty, dp, n);
        return ans;
    }
};