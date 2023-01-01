// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        unordered_map<int, int>umap;
        for(int i=0; i<n; i++){
            if(umap.find(nums[i])!=umap.end() && (i - umap[nums[i]]) <= k) return true;
            umap[nums[i]] = i;
        }
        return false;
    }
};