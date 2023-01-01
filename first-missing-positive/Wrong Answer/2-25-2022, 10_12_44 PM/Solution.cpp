// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int pos = i;
            while(pos < n && nums[pos] >= 0 && nums[pos] < n && nums[pos] != pos && nums[pos] != nums[nums[pos]]){
                swap(nums[pos], nums[nums[pos]]);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] != i)
                return i;
        }
        
        return n;
    }
};