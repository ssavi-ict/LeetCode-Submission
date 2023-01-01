// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    unordered_map<int, int>mymap;
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        vector<int>ans;

        for(int i=0; i<size; i++){
            mymap[nums[i]]++;
            if(mymap[nums[i]] == 0){
              mymap[nums[i]] = -1;
            }
            else if(mymap[nums[i]] > size/3){
              ans.push_back(nums[i]);
              mymap[nums[i]] = -1;
            }
        }
        return ans;
    }
};