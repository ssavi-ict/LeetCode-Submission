// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int count[10001];
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right = 0, ans = 0, sum = 0;
        while(right < nums.size()){
            count[nums[right]]++;
            sum = sum + nums[right];
            // cout<<"j"<<endl;
            while(count[nums[right]] > 1){
                sum = sum - nums[left];
                count[nums[left]]--;
                left++;
            }
            ans = max(ans, sum);
            right++;
        }
        return ans;
    }
};