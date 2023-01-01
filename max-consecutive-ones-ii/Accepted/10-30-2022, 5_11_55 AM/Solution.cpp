// https://leetcode.com/problems/max-consecutive-ones-ii

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = size(nums);
        vector<int>cumOne(n+1, 0);
        if(nums[0] == 1) cumOne[0] = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == 1){
                cumOne[i] = cumOne[i-1] + 1;
            }
        }
        // cout<<1<<endl;

        int maxOne = 1, lastZero = -1;
        if(nums[0] == 0) lastZero = 0;
        for(int i=1; i<n; i++){
            if(nums[i] == 0){
                lastZero = i;
                maxOne = max(maxOne, cumOne[i-1] + 1);
            }
            else{
                if(lastZero == -1) maxOne = max(maxOne, cumOne[i]);
                else if(lastZero == 0) maxOne = max(maxOne, cumOne[i] + 1);
                else maxOne = max(maxOne, cumOne[i] + cumOne[lastZero - 1] + 1);
            }
        }
        cout<<2<<endl;
        return maxOne;
    }
};