// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<(i+1)/2; j++){
                swap(matrix[j][i-j], matrix[i-j][j]);
            }
        }
        
        for(int i=n-1; i>=1; i--){
            int ii = n-1, jj = n - i;
            for(int j=0; j<i/2; j++){
                swap(matrix[jj][ii], matrix[ii][jj]);
                ii--, jj++; 
            }
        }
    }
};