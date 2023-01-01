// https://leetcode.com/problems/find-smallest-common-element-in-all-rows

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int>counter(10004, 0);
        int m = mat.size(), n = mat[0].size(), answer;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                counter[mat[i][j]]++;
            }
        }
        for(int i=1; i<=10000; i++){
            if(counter[i] == m) return i;
        }
        return -1;
    }
};