// https://leetcode.com/problems/sum-of-even-numbers-after-queries

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = size(nums), q = size(queries);
        bool isEven[n+1];
        memset(isEven, false, sizeof(isEven));
        
        int curSum = 0;
        for(int i=0; i<n; i++){
            if(!(nums[i] & 1)){
                isEven[i] = true;
                curSum += nums[i];   // isEven = 1, 3 | curSum = 2 + 4 = 6
            }
        }
        
        vector<int>ans;
        for(int i=0; i<q; i++){                               // isEven = 0, 3 | 6
            int index = queries[i][1]; // 1 , 0 | -3, 1 | -4 0 | 2 3
            int preVal = nums[queries[i][1]];                         // preVal = 1 | 2 | 2 | 4
            int curVal = nums[index] + queries[i][0];                 // curVal = 1 + 1 = 2 | 2 + (-3) = -1 | 2 -4 = -2 | 4 + 2 = 6
            
            if(!(curVal & 1)){
                if(isEven[index]){                            // 
                    curSum -= preVal;                         // 6 - 2 = 4 | 2 - 4 = -2;
                }
                else{                                      
                    isEven[index] = true;                     // 0, 1, 3
                }
                curSum += curVal;                             // 6 + 2 = 8 | 4 + (-2) = 2 | -2 +  6 = 4;
            }
            else{
                if(isEven[index]){                            
                    curSum -= preVal;                        // 8 - 2 = 6
                    isEven[index] = false;                   // 0, 3
                }
            }
            nums[index] = curVal;                           // 2 2 3 4 | 2 -1 3 4 | -2 -1 3 4
            ans.push_back(curSum);                          // 8, 6, 2, 4
        }
        return ans;
    }
};