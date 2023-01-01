// https://leetcode.com/problems/check-if-an-array-is-consecutive

class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        if(size(nums) == 1) return true;
        int sum = 0;
        int minVal = 1e6, maxVal = 0;
        for(int i=0; i<size(nums); i++){
            sum += nums[i];
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        if(!sum) return size(nums) == 1;
        long long maxSum = (maxVal * (maxVal + 1))/2;
        minVal--;
        long long minSum = (minVal * (minVal + 1))/2;
        return sum == maxSum - minSum;
    }
};