// https://leetcode.com/problems/combination-sum

class Solution {
public:
    
    void solve(int pos, int target, set<vector<int>>&combinations, vector<int> & combi, vector<int> & nums){
        if(target == 0){
            sort(combi.begin(), combi.end());
            combinations.insert(combi);
            return;
        }
        for(int i=pos; i<size(nums); i++){
            if(target - nums[i] >= 0){
                combi.push_back(nums[i]);
                solve(i, target-nums[i], combinations, combi, nums);
                combi.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> combinations;
        vector<int>combi;
        sort(candidates.begin(), candidates.end());
        solve(0, target, combinations, combi, candidates);
        vector<vector<int>>ans(combinations.begin(), combinations.end());
        return ans;
    }
};