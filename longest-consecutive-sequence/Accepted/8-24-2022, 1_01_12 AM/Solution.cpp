// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mset;
        for(int i=0; i<size(nums); i++){
            mset.insert(nums[i]);
        }
        int ans = 0;
        for(int i=0; i<size(nums); i++){
            if(mset.count(nums[i]-1) == 0){
                int val = nums[i];
                int counter = 0;
                while(mset.count(val)){
                    val++;
                    counter++;
                }
                ans = max(ans, counter);
            }
        }
        return ans;
    }
};