// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        int lo = 1;
        int hi = (n * m);
        
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            int x = (mid - 1) / (n);
            int y = (mid - 1) % n;
            if(matrix[x][y] == target)
                return true;
            else if(matrix[x][y] > target){
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return false;
    }
};