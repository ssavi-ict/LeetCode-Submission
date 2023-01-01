// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    
    vector< vector<int>>rotate90(vector<vector<int>>&mat, int row, int col){
        vector<vector<int>>matrix(row, vector<int>(col, 0));
        
        int ridx = 0;
        for(int j=0; j<col; j++){
            int cidx = 0;
            for(int i=row-1; i>=0; i--){
                matrix[ridx][cidx++] = mat[i][j];
            }
            ridx++;
        }
        
        return matrix;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        int m = mat.size();
        int n = mat[0].size();
        
        mat = rotate90(mat, m, n);
        if(mat == target) return true;
        mat = rotate90(mat, m, n);
        if(mat == target) return true;
        mat = rotate90(mat, m, n);
        if(mat == target) return true;
        return false;
    }
};