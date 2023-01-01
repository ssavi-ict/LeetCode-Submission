// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int down = 0, left = size(matrix[0]) - 1;
        while(down<size(matrix) && left>=0){
            if(target > matrix[down][left]){
                down++;
            }
            else if(target < matrix[down][left]){
                left--;
            }
            else
                return true;
        }
        return false;
    }
};