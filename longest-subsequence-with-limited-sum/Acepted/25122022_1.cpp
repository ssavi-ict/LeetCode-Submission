class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int m = queries.size(), n = nums.size();

        for(int i=1; i<n; i++){
            nums[i] += nums[i-1];
        }
        
        for(int i=0; i<m; i++){
            int max_sum = queries[i], counter = 0;
            int ubound = upper_bound(nums.begin(), nums.end(), max_sum) - nums.begin();
            queries[i] = ubound;
        }
        return queries;
    }
};