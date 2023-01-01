// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    
    int dx4[4] = {0, 1, 0, -1};
    int dy4[4] = {1, 0, -1, 0};
    // int table[201][201];
    int n, m;
    
    int solve(int u, int v, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& table){
        if(u<0 || u>=m || v<0 || v>=n) return 0;
        if(table[u][v]!=0) return table[u][v];
        // cout<<"J"<<endl;
        int ans = 0;
        for(int i=0; i<4; i++){
            int x = u + dx4[i];
            int y = v + dy4[i];
            if(x>=0 && x<m && y>=0 && y<n && (matrix[x][y] > matrix[u][v])){
                ans = max(ans, solve(x, y, m, n, matrix, table));
            }
        }
        table[u][v] = ans + 1;
        return table[u][v];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        vector<vector<int>>table(m, vector<int>(n, -1));
        int ans = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(table[i][j]==0){
                    ans = max(ans, solve(i, j, m, n, matrix, table));
                }
            }
        }
        return ans;
    }
};