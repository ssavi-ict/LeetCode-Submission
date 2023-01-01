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
            if(mset.find(nums[i]-1) == mset.end()){
                int val = nums[i];
                int counter = 0;
                while(mset.find(val) != mset.end()){
                    val++;
                    counter++;
                }
                ans = max(ans, counter);
            }
        }
        return ans;
    }
};