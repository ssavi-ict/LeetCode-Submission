// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
public:

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    bool isValid(int u, int v, int m, int n){
        return (u>=0 && u<m && v>=0 &&v<n);
    }

    int solve(int u, int v, vector<vector<int>>& grid, int m, int n, int k, vector<vector<bool>> & visited, vector<vector<vector<int>>>& dp){
        if(u == 0 && v==0) return 0;
        if(dp[u][v][k] != -1) return dp[u][v][k];
        if(grid[u][v] == 1 && k==0) return 1e6;
        if(k >= u+v) return dp[u][v][k] = u + v;

        dp[u][v][k] = 1e6;
        visited[u][v] = true;
        for(int i=0; i<4; i++){
            int x = u + dx[i];
            int y = v + dy[i];
            if(isValid(x,y,m,n)){
                dp[u][v][k] = min(dp[u][v][k], 1 + solve(x, y, grid, m, n, k - grid[u][v], visited, dp));
            }
        }
        visited[u][v] = false;
        return dp[u][v][k];
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>visited(m+1, vector<bool>(n+1, false));
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        int ans = solve(m-1, n-1, grid, m, n, k, visited, dp);
        return (ans > m*n) ? -1 : ans;
    }
};