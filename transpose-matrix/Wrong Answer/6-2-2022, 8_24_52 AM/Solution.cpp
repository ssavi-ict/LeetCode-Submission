// https://leetcode.com/problems/transpose-matrix

class Solution {
public:
    
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector< vector<int> >ans(max(n, m));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i].push_back(matrix[j][i]);
            }
        }
        return ans;
    }
};