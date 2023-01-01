// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int pos = i;
            while(nums[pos] >= 1 && nums[pos] <= n && nums[pos] != pos + 1 && nums[pos] != nums[nums[pos] - 1]){
                swap(nums[pos], nums[nums[pos] - 1]);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1)
                return i + 1;
        }
        
        return n + 1;
    }
};