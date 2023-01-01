// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = -10000;
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
        }
        if (mx < 0) return mx;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum<0) sum = 0;
            mx = max(mx, sum);
        }
        return mx;
    }
};