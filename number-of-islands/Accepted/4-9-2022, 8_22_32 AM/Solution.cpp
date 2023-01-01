// https://leetcode.com/problems/number-of-islands

class Solution {
private:
    int m, n;
void dfs(int x, int y, vector<vector<char>>&grid){
    grid[x][y] = '2';
        
    vector<vector<int>>dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    for(auto dir: dirs){
        int nx = dir[0] + x;
        int ny = dir[1] + y;
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1'){
            dfs(nx, ny, grid);
        }
    }
}
    
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        int cnt = 0;
        if(m == 0)
            return cnt;
        n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j  < n; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j , grid);
                }
            }
        }
        
        return cnt;
    }
};