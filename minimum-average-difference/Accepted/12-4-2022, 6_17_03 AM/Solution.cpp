// https://leetcode.com/problems/minimum-average-difference

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long>cumSum(n, 0);
        cumSum[0] = nums[0];
        long long Left = 0, Right = 0, minimum_abs_diff = LLONG_MAX;
        int ans;

        for(int i=1; i<n; i++){
             cumSum[i] = cumSum[i-1] + (long long)nums[i];
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