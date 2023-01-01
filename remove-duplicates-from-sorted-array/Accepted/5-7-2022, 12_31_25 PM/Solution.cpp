// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int startIndex = 1;
        for(int num: nums) {
            if(num != nums[startIndex-1]) {
                nums[startIndex++] = num;
            }
        }
        return startIndex;
    }
};