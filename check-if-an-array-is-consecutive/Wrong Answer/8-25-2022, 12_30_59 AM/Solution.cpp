// https://leetcode.com/problems/check-if-an-array-is-consecutive

class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        int sum = 0;
        int minVal = 1e6, maxVal = 0;
        for(int i=0; i<size(nums); i++){
            sum += nums[i];
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        long long maxSum = (maxVal * (maxVal + 1))/2;
        minVal--;
        long long minSum = (minVal * (minVal + 1))/2;
        return sum == maxSum - minSum;
    }
};