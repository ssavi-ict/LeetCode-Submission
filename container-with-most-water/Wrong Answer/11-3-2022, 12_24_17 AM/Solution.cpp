// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxarea = 0;
        while(left < right){
            int area = min(height[left], height[right]) * (right - left);
            if(area > maxarea){
                left++;
                maxarea = area;
            }
            else{
                right--;
            }
        }
        return maxarea;
    }
};