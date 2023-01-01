// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>mymap;
        int n = size(nums);
        int ans;
        for(int i=0; i<n; i++){
            mymap[nums[i]]++;
            if(mymap[nums[i]] > n/2){
                ans = nums[i];
            }
        }
        return ans;
    }
};