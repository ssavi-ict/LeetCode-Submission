// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = size(nums);
        vector<vector<int>>res;
        
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            // cout<<i<<endl;
            int left = i + 1, right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0) left++;
                else if(sum > 0) right--;
                else{
                    res.push_back({nums[i], nums[left++], nums[right--]});
                    while(nums[left] == nums[left+1] && left<right) left++;
                    while(nums[right] == nums[right-1] && left<right) right--;
                }
            }
        }
        
        return res;
    }
};