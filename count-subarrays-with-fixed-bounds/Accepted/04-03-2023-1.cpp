class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int start = -1, n = nums.size();
        int maxId = -1, minId =  -1;
        for(int i=0; i<n; i++){
            if(nums[i] > maxK || nums[i] < minK){
                start = i;
                maxId = minId = -1;
                continue;
            }
            if(nums[i] == maxK) maxId = i;
            if(nums[i] == minK) minId = i;
            if(maxId != -1 && minId != -1){
                ans += min(maxId, minId) - start;
            }
        }
        return ans;
    }
};