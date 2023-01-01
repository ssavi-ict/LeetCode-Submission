// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i+k<n && nums[i+k] == nums[i]) return true;
        }
        return false;
    }
};