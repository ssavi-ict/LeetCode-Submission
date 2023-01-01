// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        auto list_begin = nums.begin();
        auto list_end = nums.end();
        sort(list_begin, list_end, greater<int>());
        int kth_element = k - 1;
        return nums[kth_element];
    }
};