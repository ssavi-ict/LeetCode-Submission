class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>subSeq;
        for(int i=0; i<(1<<n); i++){
            vector<int>values;
            bool isNonDec = true;
            for(int j=0; j<n; j++){
                if(i & (1 << j)){
                    values.push_back(nums[j]);
                    int idx = values.size() - 1;
                    if(idx > 0 && values[idx] < values[idx-1]){
                        isNonDec = false;
                        break;
                    }
                }
            }
            if(values.size() > 1 && isNonDec){
                subSeq.insert(values);
            }
        }
        return vector(subSeq.begin(), subSeq.end());
       
    }
};