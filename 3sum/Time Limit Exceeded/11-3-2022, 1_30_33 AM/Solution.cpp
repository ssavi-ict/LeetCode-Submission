// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>triplets;
        
        int n = size(nums);
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int key = -1 * (nums[i] + nums[j]);
                if (binary_search(nums.begin()+j+1, nums.end(), key)){
                    vector<int>newTrip;
                    newTrip.push_back(nums[i]);
                    newTrip.push_back(nums[j]);
                    newTrip.push_back(key);
                    sort(newTrip.begin(), newTrip.end());
                    triplets.insert(newTrip);
                }
            }
        }
        vector<vector<int>>ans(triplets.begin(), triplets.end());
        return ans;
    }
};