// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, count = 0;
        for(int i=0; i<size(nums); i++){
            if(count == 0){
                count++; ans = nums[i];
            }
            else{
                count = (ans==nums[i])?count+1:count-1;
            }
        }
        return ans;
    }
};