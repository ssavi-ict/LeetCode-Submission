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
        
        long long cVal = 0, mVal = 0;
        long long ans = INT_MAX;
        
        for(int i=0; i<n; i++){
            if(i==0){
                cVal = (cum[n-1] - cum[i]);
                mVal = (long long)(n-1-i) * (long long)nums[i];
                ans = min(ans,  cVal- mVal);
            }
            else if(i == n-1){
                cVal = cum[i-1];
                mVal = (long long) nums[i]* (long long) i;
                ans = min(ans, mVal - cVal);
            }
            else{
                mVal = (long long) nums[i]* (long long)i - cum[i-1];
                cVal = (cum[n-1] - cum[i]) - (long long) (n-1-i)*(long long) nums[i];
                ans = min(ans, mVal+cVal);
            }
        }
        
        long long avgSum = 0;
        for(int i=0; i<n; i++){
            avgSum += abs(nums[i] - (cum[n-1])/n);
        }
        return min(ans, avgSum);
    }
};