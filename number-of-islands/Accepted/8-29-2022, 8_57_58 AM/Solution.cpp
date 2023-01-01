// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    
    queue<pair<int, int>>myQ;
    
    void BFS(int i, int j, vector<vector<char>>&grid, int m, int n){
        myQ.push(make_pair(i, j));
        grid[i][j] = '0';
        while(!myQ.empty()){
            auto u = myQ.front();
            myQ.pop();
            int vx = u.first, vy = u.second;
            if(vx+1 >= 0 && vx+1<m && vy>=0 && vy<n && grid[vx+1][vy] == '1'){
                grid[vx+1][vy] = '0';
                myQ.push(make_pair(vx+1, vy));
            }
            if(vx-1 >= 0 && vx-1<m && vy>=0 && vy<n && grid[vx-1][vy] == '1'){
                grid[vx-1][vy] = '0';
                myQ.push(make_pair(vx-1, vy));
            }
            
            if(vx >= 0 && vx<m && vy+1>=0 && vy+1<n && grid[vx][vy+1] == '1'){
                grid[vx][vy+1] = '0';
                myQ.push(make_pair(vx, vy+1));
            }
            
            if(vx >= 0 && vx<m && vy-1>=0 && vy-1<n && grid[vx][vy-1] == '1'){
                grid[vx][vy-1] = '0';
                myQ.push(make_pair(vx, vy-1));
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