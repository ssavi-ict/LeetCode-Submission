// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = size(nums);
        int ans = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum = sum + nums[i];
            if(sum <= 0){
                ans = max(ans, -1 * sum);
            }
        }
        return ans + 1;
    }
};