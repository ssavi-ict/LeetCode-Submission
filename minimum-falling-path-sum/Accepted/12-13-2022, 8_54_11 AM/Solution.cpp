// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = INT_MAX;
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int candidate = matrix[i][j] + matrix[i+1][j];
                if((j-1) >= 0){
                    candidate = min(candidate, matrix[i][j] + matrix[i+1][j-1]);
                }
                if((j+1)<n){
                    candidate = min(candidate, matrix[i][j] + matrix[i+1][j+1]);
                }
                matrix[i][j] = candidate;
            }
        }

        for(int i=0; i<n; i++){
            ans = min(ans, matrix[0][i]);
        }
        return ans;
    }
};