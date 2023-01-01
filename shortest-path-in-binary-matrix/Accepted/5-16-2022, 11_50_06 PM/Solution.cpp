// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    
    int dx8[8] = {0, 0, -1, 1, 1, -1, 1, -1};
    int dy8[8] = {1, -1, 0, 0, 1, -1, -1, 1};
    
    struct info{
        int x, y, dis;
    };
    info var;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        
        queue<info>Q;
        var.x = var.y = var.dis = 0;
        Q.push(var);
        grid[0][0] = 1;
        int ans = -1;
        
        while(!Q.empty()){
            auto top = Q.front();
            Q.pop();
            
            if(top.x == n-1 && top.y == n-1){
                ans = top.dis + 1;
                break;
            }
            
            for(int i=0; i<8; i++){
                int u = top.x + dx8[i];
                int v = top.y + dy8[i];
                if(u>=0 && v>=0 && u<n && v<n && grid[u][v] == 0){
                    grid[u][v] = 1;
                    var.x = u, var.y = v, var.dis = top.dis + 1;
                    Q.push(var);
                }
            }
        }
        
        return ans;
    }
};