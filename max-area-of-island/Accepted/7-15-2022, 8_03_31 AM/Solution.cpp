// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    
    int dx4[4] = {0, 0, 1, -1};
    int dy4[4] = {1, -1, 0, 0};
    int n, m;
    
    bool isOK(int u, int v, vector< vector<bool> >&visited){
        if(u>=0 && v>=0 && u<n && v<m && !visited[u][v]) return true;
        return false;
    }
    
    int dfs(vector< vector<int> > &grid, int u, int v, vector< vector<bool> > &visited){
        visited[u][v] = true;
        int ret = 0;
        for(int i=0; i<4; i++){
            int x = u + dx4[i];
            int y = v + dy4[i];
            if(isOK(x, y, visited) && grid[x][y]){
                ret = ret + dfs(grid, x, y, visited) + 1;
            }
        }
            
        return ret;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector< vector<bool> >visited(n, vector<bool>(m, false));
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] && !visited[i][j]){
                    ans = max(ans, dfs(grid, i, j, visited)+1);
                }
            }
        }
        return ans;
    }
};