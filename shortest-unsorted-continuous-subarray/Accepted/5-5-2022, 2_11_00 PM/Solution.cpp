// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stack;
        
        int start = nums.size();
        int end = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            while(!stack.empty() && nums[stack.top()] > nums[i]) {
                start = min(stack.top(), start);
                stack.pop();
            }
            stack.push(i);
        }
        while(!stack.empty())
            stack.pop();
        
        for(int i = nums.size()-1; i >= 0; i--) {
            while(!stack.empty() && nums[stack.top()] < nums[i]) {
                end = max(stack.top(), end);
                stack.pop();
            }
            stack.push(i);
        }
        
        
        if(start <= end) {
            return end - start + 1;
        }
        return 0;
        
    }
};