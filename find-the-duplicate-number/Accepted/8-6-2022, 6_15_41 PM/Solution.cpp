// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
            // cout<<slow<<' '<<fast<<endl;
        }while(slow!=fast);
        
        
        int entry = nums[0];
        while(fast!=entry){
            fast = nums[fast];
            entry = nums[entry];
        }
        return entry;
    }
};