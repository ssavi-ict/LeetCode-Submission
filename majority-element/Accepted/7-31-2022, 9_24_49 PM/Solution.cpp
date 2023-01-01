// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, n = size(nums), ans;
        for(int i=0; i<n; i++){
            if(count == 0){
                ans = nums[i];
                count++;
            }
            else{
                count = (ans==nums[i])? count + 1: count - 1;
            }
        }
        return ans;
    }
};