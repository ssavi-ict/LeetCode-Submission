// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        int n = mat[0].size();
        int row = 0, col = 0;
        for(int i=m-1; i>=0; i--){
            col = 0;
            for(int j=0; j<n; j++){
                if(target[row][col++]!=mat[i][j]) return false;
            }
            row++;
        }
        return true;
    }
};