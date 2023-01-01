// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, bool>umap;
        umap[nums[0]] = true;
        int runningSum = 0;
        for(int i=0; i<n; i++){
            runningSum += nums[i];
            runningSum %= k;
            if(umap.find(runningSum) != umap.end()) return true;
            umap[runningSum] = true;
        }
        return false;
    }
};