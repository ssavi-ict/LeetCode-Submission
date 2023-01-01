// https://leetcode.com/problems/two-sum-less-than-k

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = size(nums);
        int ans = -1;
        for(int i=0; i<n-1; i++){
            if(nums[i] > k) continue;
            int key = k - nums[i];
            int lbound = lower_bound(nums.begin()+i+1, nums.end(), key) - nums.begin();
            // cout<<nums[i]<<' '<<nums[lbound]<<endl;
            if((lbound-1 != i) && (nums[lbound-1] + nums[i]) <= k) ans = max(ans, nums[lbound-1] + nums[i]);
        }
        return ans;
    }
};