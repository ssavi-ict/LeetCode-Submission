// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    void BFS(int i, int j, vector<vector<char>>&grid, int m, int n){
        queue<pair<int, int>>myQ;
        myQ.push(make_pair(i, j));
        grid[i][j] = '0';
        while(!myQ.empty()){
            auto u = myQ.front();
            myQ.pop();
            for(int i=0; i<4; i++){
                int vx = u.first + dx[i], vy = u.second + dy[i];
                if(vx>=0 && vy>=0 && vx<m && vy<n && grid[vx][vy]=='1'){
                    grid[vx][vy] = '0';
                    myQ.push(make_pair(vx, vy));
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    BFS(i, j, grid, m, n);
                }
            }
        }
        return cnt;
    }
};