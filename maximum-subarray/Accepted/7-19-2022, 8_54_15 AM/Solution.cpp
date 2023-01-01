// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for(int i=0; i<size(nums); i++){
            sum = sum + nums[i];
            ans = max(ans, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return ans;
    }
};