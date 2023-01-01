// https://leetcode.com/problems/majority-element-ii

class Solution {
public:

    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
  
  int one = NULL, two = NULL;
  int one_count = 0, two_count = 0;
  
  for(int i=0; i<size; i++){
    if(one_count == 0){
      one_count++;
      one = nums[i];
    }
    else if(two_count==0){
      two_count++;
      two = nums[i];
    }
    else if(one_count==nums[i]){
      one_count++;
    }
    else if(two_count==nums[i]){
      two_count++;
    }
    else{
      one_count--;
      two_count--;
    }
  }
  
  vector<int>ans;
  one_count = 0, two_count = 0;
  for(int i=0; i<size; i++){
    if(one==nums[i]) one_count++;
    else if(two==nums[i]) two_count++;
  }
  
  if(one_count > size/3) ans.push_back(one);
  if(two_count > size/3) ans.push_back(two);
  return ans;
  
    }
};