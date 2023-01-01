// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
public:

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int u, int v, int m, int n){
        return (u>=0 && u<m && v>=0 &&v<n);
    }

    int solve(int u, int v, vector<vector<int>>& grid, int m, int n, int k, vector<vector<bool>> & visited, vector<vector<vector<vector<int>>>>& dp, int dir){
        if(k<0) return 1e6;
        if(u == m-1 && v==n-1 && k>=0) return 0;
        if(dp[u][v][k][dir] != -1) return dp[u][v][k][dir];
        int ret = 1e6;
        // visited[u][v] = true;
        for(int i=0; i<4; i++){
            int x = u + dx[i];
            int y = v + dy[i];
            if(isValid(x,y,m,n) && !visited[x][y]){
                visited[x][y] = true;
                if(grid[x][y] == 1){
                    ret = min(ret, 1 + solve(x, y, grid, m, n, k-1, visited, dp, i));
                }
                if(grid[x][y] == 0){
                    ret = min(ret, 1 + solve(x, y, grid, m, n, k, visited, dp, i));
                }
                visited[x][y] = false;
            }
        }
        // visited[u][v] = false;
        return dp[u][v][k][dir] = ret;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>visited(m+1, vector<bool>(n+1, false));
        vector<vector<vector<vector<int>>>>dp(m+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(k+1, vector<int>(4, -1))));
        int ans = solve(0, 0, grid, m, n, k, visited, dp, 0);
        return (ans > m*n) ? -1 : ans;
    }
};