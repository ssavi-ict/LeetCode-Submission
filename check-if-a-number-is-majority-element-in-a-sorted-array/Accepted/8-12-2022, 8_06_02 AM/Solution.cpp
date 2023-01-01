// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int lbound = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ubound = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return (ubound-lbound)>size(nums)/2;
    }
};