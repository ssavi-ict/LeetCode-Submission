// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, entry = 0, n = size(nums);
        do{
            slow = (slow + 1 == n) ? 0 : slow + 1;
            fast = (fast + 1 == n) ? 0 : fast + 1;
            fast = (fast + 1 == n) ? 0 : fast + 1;
            
        }while(nums[slow]!=nums[fast]);
        
        while(nums[entry]!=nums[slow]){
            slow = (slow + 1 == n) ? 0 : slow + 1;
            entry++;
        }
        
        return nums[slow];
    }
};