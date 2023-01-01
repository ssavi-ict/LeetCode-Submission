// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = size(nums);
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        for(int i=0; i<n; i++){
            if(i == 0 || nums[i] < first){
                first = nums[i];
            }
            else if(nums[i] > first || second == INT_MIN){
                if(nums[i] > second && second != INT_MIN){
                    return true;
                }
                second = nums[i];
            }
        }
        return false;
    }
};