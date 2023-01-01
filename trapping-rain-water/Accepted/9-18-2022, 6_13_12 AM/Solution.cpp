// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>maxLeft(n, 0);
        vector<int>maxRight(n, 0);
        
        maxLeft[0] = height[0], maxRight[n-1] = height[n-1];
        for(int i=1; i<n; i++){
            maxLeft[i] = max(height[i], maxLeft[i-1]);
            maxRight[n-i-1] = max(height[n-i-1], maxRight[n-i]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            int minMax = min(maxLeft[i], maxRight[i]);
            ans += (minMax - height[i]);
        }
        return ans;
    }
};