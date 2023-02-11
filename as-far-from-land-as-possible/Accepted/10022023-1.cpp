class Solution {
public:

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    int bfs(vector<vector<int>> & grid, int n, int m, queue<pair<int, int>> & gridQueue , vector<vector<bool>>&visited){
        int stepCount = 0;
        while(!gridQueue.empty()){
            int queueSize = gridQueue.size();
            while(queueSize--){
                auto topCell = gridQueue.front();
                gridQueue.pop();
                for(int i=0; i<4; i++){
                    int currentX = topCell.first + dx[i];
                    int currentY = topCell.second + dy[i];
                    if(currentX < 0 || currentY < 0 || currentX >= n || currentY >= m || visited[currentX][currentY])
                    continue;
                    visited[currentX][currentY] = true;
                    gridQueue.push({currentX, currentY});
                }
            }
            stepCount++;
        }
        return stepCount;
    }

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = -1;
        queue<pair<int, int>>gridQueue;
        vector<vector<bool>>visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    gridQueue.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        if(gridQueue.size() == 0 || gridQueue.size() == n*m) return -1;
        ans  = bfs(grid, n, m, gridQueue, visited);
        return ans - 1;
    }
};