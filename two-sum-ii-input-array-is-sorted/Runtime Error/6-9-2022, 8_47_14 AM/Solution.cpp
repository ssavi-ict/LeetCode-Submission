// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    int has[2001];
    vector<int> twoSum(vector<int>& numbers, int target) {
        memset(has, -1, sizeof(has));
        for(int i=0; i<numbers.size(); i++){
            has[numbers[i] + 1000] = i;
        }
        vector<int>ans;
        for(int i=0; i<numbers.size(); i++){
            int left = (target+1000) - numbers[i];
            if(has[left]!=-1){
                ans.push_back(i+1);
                ans.push_back(has[left] + 1);
                break;
            }
        }
        return ans;
    }
};