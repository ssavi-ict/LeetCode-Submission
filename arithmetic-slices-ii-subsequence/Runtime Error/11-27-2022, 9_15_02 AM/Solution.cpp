// https://leetcode.com/problems/arithmetic-slices-ii-subsequence

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = size(nums);
        unordered_map<long long, int>dp[n+1];
        int nums_of_slices = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long long diff = nums[i] - nums[j];
                int sum = 0;
                if(dp[j].find(diff) != dp[j].end()){
                    sum += dp[j][diff];
                }
                dp[i][diff] += sum + 1;
                nums_of_slices += sum;
            }
        }
        return nums_of_slices;
    }
};