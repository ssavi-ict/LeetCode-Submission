// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int count = 1, ans = nums[0], mx = 1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]){
                count++; 
            }
            else{
                count = 1;
            }
            
            if(mx < count){
                mx = count;
                ans = nums[i];
            }
        }
        if(ans != target) return false;
        return (mx > (n/2));
    }
};