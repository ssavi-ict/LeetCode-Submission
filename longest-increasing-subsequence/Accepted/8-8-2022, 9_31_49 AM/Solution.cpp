// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), lis = 1;
        
        vector<int>lisVal;
        lisVal.push_back(nums[0]);
        for(int i=1; i<n; i++){
            int idx = lower_bound(lisVal.begin(), lisVal.end(), nums[i]) - lisVal.begin();
            if(idx>=lisVal.size()){
                lis++;
                lisVal.push_back(nums[i]);
            }
            else
                lisVal[idx] = nums[i];
        }
        return lis;
    }
};

/*

lisVal = 0, 1, 2, 3 
lis = 4

*/