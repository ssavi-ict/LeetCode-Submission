// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int startIndex = 0;
        for(int num: nums) {
            if(num != val)
                nums[startIndex++] = num;
        }
        return startIndex;
    }
};