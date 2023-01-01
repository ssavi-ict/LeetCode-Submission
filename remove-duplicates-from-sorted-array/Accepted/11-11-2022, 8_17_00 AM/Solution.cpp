// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1, n = size(nums);
        while(right < n){
            if(nums[right] == nums[right - 1]) right++;
            else{
                left++;
                nums[left] = nums[right];
                right++;
            }
        }
        return left + 1;
    }
};