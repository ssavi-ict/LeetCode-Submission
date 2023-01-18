class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0, n = nums.size(), totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum += nums[i];
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        if(maxSum < 0) return maxSum;

        sum = 0;
        int minSum = INT_MAX;
        for(int i=0; i<n; i++){
            sum += nums[i];
            minSum = min(minSum, sum);
            if(sum > 0) sum = 0;
        }
        maxSum = max(maxSum, totalSum - minSum);
        return maxSum;
    }
};