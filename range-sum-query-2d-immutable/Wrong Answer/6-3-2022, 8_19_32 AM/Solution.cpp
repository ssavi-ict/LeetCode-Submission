// https://leetcode.com/problems/range-sum-query-2d-immutable

class NumMatrix {
public:
    int cum[201][201], row, col;
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(j == 0) cum[i][j] = matrix[i][j];
                else cum[i][j] = cum[i][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i=row1; i<=row2; i++){
            int to = (col1 - 1) <= 0 ? 0 : col1 - 1;
            ans = ans + (cum[i][col2] - cum[i][to]);
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */