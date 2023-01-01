class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxVal = 0;
        for(int i=0; i<nums.size()-1; i++){
            maxVal = max(maxVal, nums[i] + i);
            if(maxVal <= i) return false;
        }
        return true;
    }
};