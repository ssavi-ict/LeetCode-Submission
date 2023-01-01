// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
    int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};

    bool isValid(int u, int v, int n){
        if(u>=0 && u<n && v>=0 && v<n) return true;
        return false;
    }

    void getDistance(vector<vector<int>> & matrix, vector<vector<int>> & distance, int n){
        distance[0][0] = 1;
        queue<pair<int, int>>myQ;
        myQ.push(make_pair(0, 0));
        while(!myQ.empty()){
            auto top = myQ.front();
            myQ.pop();
            for(int i=0; i<8; i++){
                int u = top.first + dx[i];
                int v = top.second + dy[i];
                if(isValid(u, v, n) && matrix[u][v] == 0 && distance[u][v] > distance[top.first][top.second] + 1){
                    distance[u][v] = distance[top.first][top.second] + 1;
                    myQ.push(make_pair(u,v));
                }
            }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>matrix(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = grid[i][j];
            }
        }
        if(grid[0][0]) return -1;
        vector<vector<int>>distance(n, vector<int>(n, INT_MAX));
        getDistance(grid, distance, n);
        return (distance[n-1][n-1] < INT_MAX) ? distance[n-1][n-1] : -1 ;
    }
};