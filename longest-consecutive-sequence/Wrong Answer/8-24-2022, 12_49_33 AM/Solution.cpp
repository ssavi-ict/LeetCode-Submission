// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool>mymap;
        for(int i=0; i<size(nums); i++){
            mymap[nums[i]] = true;
        }
        int ans = 0;
        for(int i=0; i<size(nums); i++){
            if(mymap.find(nums[i]-1)!=mymap.end()){
                int val = nums[i];
                int counter = 1;
                while(mymap[val]){
                    val++;
                    counter++;
                }
                ans = max(ans, counter);
            }
        }
        return ans;
    }
};