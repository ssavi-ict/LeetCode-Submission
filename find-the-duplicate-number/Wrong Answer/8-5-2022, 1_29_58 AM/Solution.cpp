// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sum = 0, cnt= 1;
        for(int i=0; i<size(nums); i++){
            sum += nums[i];
            if(i<size(nums)-1){
                sum -= cnt;
                cnt++;
            }
        }
        return sum;
    }
};