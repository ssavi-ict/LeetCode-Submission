// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=n-2; i>=0; i--){
            if(nums[i]>nums[i+1])
            {
                cnt++;
                if(i+1==n-1){
                    nums[i+1] = nums[i];
                }
                else if(i==0){
                    nums[i] = nums[i+1];
                }
                else if(i+2<n && nums[i]<=nums[i+2]){
                    nums[i+1] = nums[i+2];
                }
                else{
                    nums[i] = nums[i+1];
                }
            }
        }
        // cout<<cnt<<endl;
        return cnt<=1;
    }
};