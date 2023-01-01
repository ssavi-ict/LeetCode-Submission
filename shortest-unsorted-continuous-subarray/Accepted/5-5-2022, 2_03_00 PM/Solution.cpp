// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> snums(nums);
        sort(snums.begin(), snums.end());
        int start = nums.size();
        int end = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != snums[i]) {
                start = min(start, i);
                end = max(end, i);
            }
        }
        if(start <= end) {
            return end - start + 1;
        }
        return 0;
        
    }
};