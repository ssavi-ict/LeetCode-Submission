// https://leetcode.com/problems/split-array-into-consecutive-subsequences

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int>counter;
        for(int i=0; i<size(nums); i++){
            counter[nums[i]]++;
        }
        unordered_map<int, int>required;
        for(int i=0; i<size(nums); i++){
            if(required[nums[i]] && counter[nums[i]]){
                required[nums[i]]--;
                counter[nums[i]]--;
                required[nums[i]+1]++;
            }
            else if(counter[nums[i]] && counter[nums[i]+1] && counter[nums[i]+2]){
                counter[nums[i]]--;
                counter[nums[i]+1]--;
                counter[nums[i]+2]--;
                required[nums[i]+3]++;
            }
            else if(counter[nums[i]]){
                    return false;
            }
        }
        return true;
    }
};