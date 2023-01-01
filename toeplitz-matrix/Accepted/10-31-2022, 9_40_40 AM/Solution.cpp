// https://leetcode.com/problems/toeplitz-matrix

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<n; i++){
            int st_x = 0, st_y = i; 
            int num = matrix[st_x][st_y];
            while(true){
                if(matrix[st_x][st_y] != num) return false;
                st_x++, st_y++;
                if(st_x >= m || st_y >= n) break;
            }
        }

        for(int i=1; i<m; i++){
            int st_x = i, st_y = 0;
            int num = matrix[st_x][st_y];
            while(true){
                if(matrix[st_x][st_y] != num) return false;
                st_x++, st_y++;
                if(st_x >= m || st_y >= n) break;
            }
        }
        return true;
    }
};