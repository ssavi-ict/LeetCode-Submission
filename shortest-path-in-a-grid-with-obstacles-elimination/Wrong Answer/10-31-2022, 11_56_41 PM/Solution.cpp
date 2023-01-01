// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
public:

    struct info{
        int u, v, rem;
    };

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool isValid(int u, int v, int m, int n){
        return (u>=0 && u<m && v>=0 && v<n);
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // if(k >= m + n) return m + n;
        vector<vector<vector<bool>>>visited(m+1, vector<vector<bool>>(n+1, vector<bool>(k+1, false)));
        queue<info>myQ;
        myQ.push({0,0,k});
        visited[0][0][k] = true;
        int counter = 0;

        while(!myQ.empty()){
            int q_size = myQ.size();
            while(q_size--){
                auto top = myQ.front();
                int u = top.u, v = top.v, rem = top.rem;
                if(u == m-1 && v==n-1) return counter;
                myQ.pop();
                for(int i=0; i<4; i++){
                    int x = u + dx[i];
                    int y = v + dy[i];
                    if(!isValid(x,y,m,n)) continue;
                    if(grid[x][y] == 0 && !visited[x][y][rem]){
                        visited[x][y][rem] = true;
                        myQ.push({x,y,k});
                    }
                    else if(grid[x][y] == 1 && rem && !visited[x][y][rem-1]){
                        visited[x][y][rem-1] = true;
                        myQ.push({x,y,rem-1});
                    }
                }
            }
            counter++;
        }
        return -1;
    }
};