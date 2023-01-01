// https://leetcode.com/problems/out-of-boundary-paths

class Solution {
public:
    int M, N;
    int dp[51][51][51];
    const int mod = 1000000000 + 7;
    
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    bool valid(int x, int y){
        if(x<0 || y<0 || x>=M || y>=N) return true;
        return false;
    }
    
    int solve(int u, int v, int maxMove){
        if(valid(u, v)) return 1;
        if(maxMove <= 0) return 0;
        if(dp[u][v][maxMove]!=-1) return dp[u][v][maxMove];
        int ret = 0;
        for(int i=0; i<4; i++){
            int x = u + dx[i];
            int y = v + dy[i];
            ret = (ret%mod + solve(x, y, maxMove-1)%mod)%mod;
        }
        return (dp[u][v][maxMove] = ret%mod);
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M = m, N = n;
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, maxMove);
    }
};