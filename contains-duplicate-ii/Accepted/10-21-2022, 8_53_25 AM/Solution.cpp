// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>umap;
        for(int i=0; i<n; i++){
            if(umap.find(nums[i])!=umap.end() && (i - umap[nums[i]]) <= k) return true;
            umap[nums[i]] = i;
        }
        return false;
    }
};