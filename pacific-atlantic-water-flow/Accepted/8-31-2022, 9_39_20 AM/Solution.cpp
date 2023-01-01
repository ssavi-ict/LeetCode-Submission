// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
public:
    
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    
    vector<vector<bool>>bfs(vector<vector<int>>& heights, queue<pair<int, int>> & Q, int m, int n){
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        while(!Q.empty()){
            auto top = Q.front();
            visited[top.first][top.second] = true;
            Q.pop();
            for(int i=0; i<4; i++){
                int x = top.first + dx[i];
                int y = top.second + dy[i];
                if(x>=0 && x<m && y>=0 && y<n && !visited[x][y]){
                    if(heights[x][y] >= heights[top.first][top.second]){
                        Q.push(make_pair(x, y));
                    }
                }
            }
        }
        return visited;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        
        queue<pair<int, int>>pacific, atlantic;
        for(int i=0; i<m; i++){
            pacific.push(make_pair(i, 0));
            atlantic.push(make_pair(i, n-1));
        }
        
        for(int i=0; i<n; i++){
            pacific.push(make_pair(0, i));
            atlantic.push(make_pair(m-1, i));
        }
        
        vector<vector<bool>>pacificVisited = bfs(heights, pacific, m, n);
        vector<vector<bool>>atlanticVisited = bfs(heights, atlantic, m, n);
        
        vector<vector<int>>ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};