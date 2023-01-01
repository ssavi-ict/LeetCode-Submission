// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>umap;
        int runningSum = 0;
        for(int i=0; i<n; i++){
            runningSum += nums[i];
            runningSum %= k;
            if(!runningSum || umap.find(runningSum) != umap.end()){
                if(umap[runningSum] < i) return true;
            }
            else umap[runningSum] = i + 1;
        }
        return false;
    }
};