// https://leetcode.com/problems/find-smallest-common-element-in-all-rows

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int>counter(10004, 0);
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                counter[mat[i][j]]++;
                if(counter[mat[i][j]] == m) return mat[i][j];
            }
        }
        return -1;
    }
};