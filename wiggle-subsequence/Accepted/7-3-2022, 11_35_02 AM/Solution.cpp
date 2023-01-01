// https://leetcode.com/problems/wiggle-subsequence

class Solution {
public:
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int diff = 0, pos = 0;
        bool plus = true, minus = true;
        int cnt = 0;
        for(int i=1; i<n; i++){
            diff = nums[i] - nums[pos];
            if(!diff) continue;
            if(diff < 0){
                if(minus){
                    cnt++;
                    minus = false, plus = true;
                }
                if(nums[i] <= nums[pos]){
                    pos = i;
                }
            }
            else{
                if (plus){
                    cnt++;
                    minus = true, plus = false;
                }
                if(nums[i] >= nums[pos]){
                    pos = i;
                }
            }
            // cout<<pos<<' '<<cnt<<endl;
        }
        return cnt + 1;
    }
};