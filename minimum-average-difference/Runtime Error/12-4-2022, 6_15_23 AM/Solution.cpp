// https://leetcode.com/problems/minimum-average-difference

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>cumSum(n, 0);
        cumSum[0] = nums[0];
        int Left = 0, Right = 0, ans, minimum_abs_diff = INT_MAX;

        for(int i=1; i<n; i++){
             cumSum[i] = cumSum[i-1] + nums[i];
        }

        for(int i=0; i<n; i++){
            Left = cumSum[i] / (i + 1);
            Right = (cumSum[n-1] - cumSum[i]) / ((n - 1 == i)? 1 : n - i - 1);
            int abs_diff = abs(Left - Right);
            if(abs_diff < minimum_abs_diff){
                minimum_abs_diff = abs_diff;
                ans = i;
            }
        }
        return ans;
    }
};