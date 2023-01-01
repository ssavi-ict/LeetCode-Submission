// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                swap(matrix[j][i], matrix[j][n-i-1]);
            }
        }
        
        
        for(int i=0; i<n; i++){ 
            int to = n-i; 
            int stR = i, stC = 0;
            int bkR = n-1, bkC = n-i-1;
            for(int j=0; j<to/2; j++){
                swap(matrix[stR++][stC++], matrix[bkR--][bkC--]);
            }
        }
        
        for(int i=1; i<n; i++){
            int to = n-i;  
            int stR = 0, stC = i;
            int bkR = n-i-1, bkC = n-1;
            for(int j=0; j<to/2; j++){
                swap(matrix[stR++][stC++], matrix[bkR--][bkC--]);
            }
        }
    }
};

/*

2, 3-0-1 = 2, 2

(1,0) | (2,1)

*/