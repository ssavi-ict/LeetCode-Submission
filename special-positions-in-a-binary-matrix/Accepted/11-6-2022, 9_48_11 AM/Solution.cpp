// https://leetcode.com/problems/special-positions-in-a-binary-matrix

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int>rowOne(m, 0), colOne(n, 0);
        for(int i=0; i<m; i++){
            int countOne = 0;
            for(int j=0; j<n; j++){
                countOne+= mat[i][j];
            }
            rowOne[i] = countOne;
        }
        
        for(int i=0; i<n; i++){
            int countOne = 0;
            for(int j=0; j<m; j++){
                countOne += mat[j][i];
            }
            colOne[i] = countOne;
        }
        
        
        int specialCount = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1 && rowOne[i]==1 && colOne[j]==1) specialCount++;
            }
        }
        return specialCount;
    }
};