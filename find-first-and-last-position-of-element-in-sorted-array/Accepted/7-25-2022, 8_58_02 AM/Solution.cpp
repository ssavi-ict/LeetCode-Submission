// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = size(nums);
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        vector<int>ans(2, -1);
        if(lb>=0 && lb<n&& ub>=0 && ub<=n){
            if(nums[lb] == target) ans[0] = lb;
            if(ub > 0 && nums[ub-1] == target) ans[1] = ub-1;
        }
        return ans;
    }
};

// 4 5 6 7 8 | 3
// 4 5 6 7 8 | 9
// 4 5 6 7 8 | 4
// 4 5 6 7 8 | 8