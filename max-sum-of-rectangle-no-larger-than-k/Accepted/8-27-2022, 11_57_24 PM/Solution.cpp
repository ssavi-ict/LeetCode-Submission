// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;
        
        vector<int>sum(m, 0);
        bool flag;
        for(int col = 0; col<n; col++){
            flag = false;
            for(int i = col; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!flag) sum[j] = 0;
                    sum[j]+=matrix[j][i];
                }
                
                set<int>sumSet;
                sumSet.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for(auto sval:sum){
                    curSum += sval;
                    auto it = sumSet.lower_bound(curSum - k);
                    if(it!=sumSet.end()){
                        curMax = max(curMax, curSum - *it);
                        if(curMax == k) return k;
                    }
                    sumSet.insert(curSum);
                }
                ans = max(ans, curMax);
                flag = true;
            }
        }
        return ans;
    }
};

/*

1 0  1
0 -2 3

Iteration 1     | Iteration 2   | Iteration 3
sum = 1, 1      | 1, -2         | 2, 1
sumSet = 0, 1,  | 0, 1, -2      | 0, 2, 3
curMax = 1      | 1             | 2
ans = 1         | 1             | 2
    
Iteration 1     | Iteration 2
sum = 0, -2     | sum = 1, 1
sumSet = 0, -2  | sumSet = 0, 1, 2
curMax = 0      | curMax = 2
ans = 2         | ans = 2

Iteraton 1
sum = 1, 3
sumSet = 0, 1, 2
curMax = 1
ans = 2

*/