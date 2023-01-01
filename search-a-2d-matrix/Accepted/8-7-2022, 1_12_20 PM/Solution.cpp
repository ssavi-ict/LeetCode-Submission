// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = size(matrix), m = size(matrix[0]);
        int lo = 0, hi =  n*m-1;
        
        if(lo==hi){
            return (matrix[lo][hi]==target);
        }
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            // cout<<lo<<' '<<mid<<' '<<hi<<endl;
            int row = mid/m, col = mid%m;
            int mid_el = matrix[row][col];
            if(mid_el == target) return true;
            else if(mid_el > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};

// 1 3 5 7 10 11 16 20 23 30 34 60 | 3
// lo = 0, hi = 11
// mid = 0 + (11 - 0)/2 = 5, mid_el = mat[1][1] = 5