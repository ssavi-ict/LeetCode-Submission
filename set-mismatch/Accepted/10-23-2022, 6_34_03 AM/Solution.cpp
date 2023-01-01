// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = nums.size();
        vector<bool>occurs(n+1, false);
        int twice, missing;
        for(int i=0; i<n; i++){
            if(occurs[nums[i]] == true){
                twice = nums[i];
            }
            occurs[nums[i]] = true;
        }

        for(int i=1; i<=n; i++){
            if(!occurs[i]){
                missing = i; break;
            }
        }
        return {twice, missing};
    }
};