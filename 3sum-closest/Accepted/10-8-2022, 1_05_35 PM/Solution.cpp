// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // -4, -1, 1, 2

        int n = nums.size();
        int ans = -10000001;

        for(int i=0; i<n-1; i++){ // -4
            int lo = i + 1, hi = n - 1;
            int sum_three = 0;
            while(lo < hi){
                sum_three = nums[i] + nums[lo] + nums[hi];
                if(sum_three == target){
                    return target;
                }
                else if(sum_three < target){
                    if(abs(target - sum_three)  < abs(target - ans)){
                        ans = sum_three;
                    }
                    ++lo;
                }
                else{
                    if(abs(target - sum_three)  < abs(target - ans)){
                        ans = sum_three;
                    }
                    --hi;
                }
            }
            
            // int sum_three = nums[i] + nums[lo] + nums[hi];
        }
        return ans;
    }
};