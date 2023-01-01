// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int positiveEnd = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                nums[positiveEnd++] = nums[i];
            }
        }
        
        for(int i = 0; i < positiveEnd; i++) {
            if(nums[i] <= positiveEnd) {
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            }
        }
        int result = positiveEnd + 1;
        for(int i = 0; i < positiveEnd; i++) {
            if(nums[i] > 0)
                return i + 1;
        }

        return result;
        
    }
};