// https://leetcode.com/problems/check-if-an-array-is-consecutive

class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        unordered_map<int, int>umap;
        
        if(size(nums) == 1) return true;
        long long sum = 0;
        long long minVal = 1e6, maxVal = 0;
        for(int i=0; i<size(nums); i++){
            sum += nums[i];
            minVal = min(minVal, (long long)nums[i]);
            maxVal = max(maxVal, (long long)nums[i]);
            umap[nums[i]]++;
            if(umap[nums[i]] > 1) return false;
        }
        long long maxSum = (maxVal * (maxVal + 1))/2;
        minVal--;
        long long minSum = (minVal * (minVal + 1))/2;
        return sum == maxSum - minSum;
    }
};