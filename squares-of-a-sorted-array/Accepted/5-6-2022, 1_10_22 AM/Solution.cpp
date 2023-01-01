// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    int square(int num) {
        return num * num;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            if(square(nums[left]) <= square(nums[right])) {
                result.push_back(square(nums[right]));
                right--;
            }
            else {
                result.push_back(square(nums[left]));
                left++;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};