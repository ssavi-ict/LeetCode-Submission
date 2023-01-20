class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int>frequency;
        int n = nums.size(), sum = 0;
        vector<int>prefixSum(n, 0);
        
        frequency[0]++;
        int ans = 0;
        for(int i=0; i<n; i++){
            prefixSum[i] = ((i - 1) < 0 ? 0 : prefixSum[i-1]) + nums[i];
            int modValue = (prefixSum[i]%k < 0) ? (prefixSum[i]%k) + k : prefixSum[i]%k;
            ans += frequency[modValue];
            frequency[modValue]++;
        }
        return ans;
    }
};