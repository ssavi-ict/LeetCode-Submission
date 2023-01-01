// https://leetcode.com/problems/check-if-an-array-is-consecutive

class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        unordered_map<int, int>umap;
        
        if(size(nums) == 1) return true;
        long long minVal = 1e6, maxVal = 0;
        for(int i=0; i<size(nums); i++){
            minVal = min(minVal, (long long)nums[i]);
            maxVal = max(maxVal, (long long)nums[i]);
            umap[nums[i]]++;
            if(umap[nums[i]] > 1) return false;
        }
        
        for(int i=minVal; i<=maxVal; i++){
            if(umap[i] == 0) return false;
        }
        return true;
    }
};