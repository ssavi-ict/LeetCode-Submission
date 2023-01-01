// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        vector< pair<int, int>>nums_idx;
        for(int i=0; i<n; i++){
            nums_idx.push_back(make_pair(nums[i], i));
        }
        sort(nums_idx.begin(), nums_idx.end());
        for(int i=0; i<n; i++){
            if(i+1<n && nums_idx[i].first == nums_idx[i+1].first && (nums_idx[i+1].second-nums_idx[i].second) <= k){
                return true;
            }
        }
        return false;
    }
};