class Solution {
public:

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int pathFind(vector<vector<int>> & grid, vector<vector<bool>>&visited, int x, int y, int m, int n, int nobs){
        if(grid[x][y] == 2){
            return (nobs == -1);
        }
        int ret = 0;
        for(int i=0; i<4; i++){
            int adj_x = x + dx[i];
            int adj_y = y + dy[i];
            if(adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y>= n) continue;
            if(grid[adj_x][adj_y] == -1 || visited[adj_x][adj_y]) continue;
            visited[adj_x][adj_y] = true;
            ret += pathFind(grid, visited, adj_x, adj_y, m, n, nobs-1);
            visited[adj_x][adj_y] = false;
        }
        return ret;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m+1, vector<bool>(n+1, false));
        int srcx, srcy;
        int nobs = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    srcx = i, srcy= j;
                }
                if(grid[i][j] == 0) nobs++;
            }
        }
        // cout<<nobs<<endl;
        visited[srcx][srcy] = true;
        return pathFind(grid, visited, srcx, srcy, m, n, nobs);
    }
};