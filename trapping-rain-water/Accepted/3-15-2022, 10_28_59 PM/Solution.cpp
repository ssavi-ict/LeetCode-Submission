// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = height[0];
        int right_max = height[right];
        int result = 0;
        
        while(left < right){
            result += max(0, (min(left_max, right_max) - min(height[left], height[right])));
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if(left_max <= right_max)
                left++;
            else right--;
        }
        
        return result;
    }
};