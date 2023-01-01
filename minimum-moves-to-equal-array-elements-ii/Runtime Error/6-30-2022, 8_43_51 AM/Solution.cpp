// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long cum[n+1];
        cum[0] = nums[0];
        
        for(int i=1; i<n; i++){
            cum[i] = cum[i-1] + nums[i];
        }
        
        long long sum = cum[n-1];
        long long ans = INT_MAX;
        
        for(int i=0; i<n; i++){
            if(i==0){
                ans = min(ans, (cum[n-1] - cum[i]) - (n-1-i)*nums[i]);
            }
            else if(i == n-1){
                ans = min(ans, nums[i]*(i)-cum[i-1]);
            }
            else{
                long long left = nums[i]*(i)-cum[i-1];
                long long right = (cum[n-1] - cum[i]) - (n-1-i)*nums[i];
                ans = min(ans, left+right);
            }
        }
        
        long long avgSum = 0;
        for(int i=0; i<n; i++){
            avgSum += abs(nums[i] - (cum[n-1])/n);
        }
        return min(ans, avgSum);
    }
};