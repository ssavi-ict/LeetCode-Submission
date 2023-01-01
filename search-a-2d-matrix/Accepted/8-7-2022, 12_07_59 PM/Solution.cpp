// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<size(matrix); i++){
            if(binary_search(matrix[i].begin(), matrix[i].end(), target)) return true;
        }
        return false;
    }
};