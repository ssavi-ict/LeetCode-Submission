// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        vector< pair<int, int>>nums_idx;
        for(int i=0; i<n; i++){
            nums_idx.push_back(make_pair(nums[i], i));
        }
        sort(nums_idx.begin(), nums_idx.end());
        for(int i=0; i<n; i++){
            if(i+1<n && abs(nums_idx[i+1].first-nums_idx[i].first)<=valueDiff && abs(nums_idx[i+1].second - nums_idx[i].second) <= indexDiff){
                return true;
            }
        }
        return false;
    }
};