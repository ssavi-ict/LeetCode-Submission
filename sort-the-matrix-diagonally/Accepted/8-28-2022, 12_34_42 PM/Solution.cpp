// https://leetcode.com/problems/sort-the-matrix-diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int col = 0;
        for(int i=m-1; i>=0; i--){
            int row = (col>=n) ? i+n-1: m-1; int temp_row = row;
            if(col >= n) col--;
            
            vector<int>values;
            for(int j=col; j>=0; j--){
                values.push_back(mat[row--][j]);
            }
            sort(values.begin(), values.end());
            int sz = values.size();
            row = temp_row;
            for(int j=col; j>=0; j--){
                mat[row--][j] = values[--sz];
            }
            col++;
        }
        
        int row = 0;
        for(int i=n-1; i>=1; i--){
            int col = i;
            vector<int>values;
            for(int j=0; j<=row; j++){
                values.push_back(mat[j][col++]);
            }
            sort(values.begin(), values.end());
            int idx = 0;
            col = i;
            for(int j=0; j<=row; j++){
                mat[j][col++] = values[idx++];
            }
            
            row++;
            if(row>=m) row--;
        }
        return mat;
    }
};

/*
m = 3, n = 4
3 3 1 1
2 2 1 2
1 1 1 2



*/