// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mset(nums.begin(), nums.end());
        int ans = 0;
        for(auto & it:mset){
            if(mset.count(it-1) == 0){
                int counter = 1;
                while(mset.count(it + counter)){
                    counter++;
                }
                ans = max(ans, counter);
            }
        }
        return ans;
    }
};