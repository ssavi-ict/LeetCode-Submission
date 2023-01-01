// https://leetcode.com/problems/split-array-into-consecutive-subsequences

class Solution {
public:
    
    int counter[2001], required[2002];
    
    bool isPossible(vector<int>& nums) {
        // unordered_map<int, int>counter;
        for(int i=0; i<size(nums); i++){
            counter[nums[i]+1000]++;
        }
        // unordered_map<int, int>required;
        for(int i=0; i<size(nums); i++){
            if(required[nums[i]+1000] && counter[nums[i]+1000]){
                required[nums[i]+1000]--;
                counter[nums[i]+1000]--;
                required[nums[i]+1+1000]++;
            }
            else if(counter[nums[i]+1000] && counter[nums[i]+1+1000] && counter[nums[i]+2+1000]){
                counter[nums[i]+1000]--;
                counter[nums[i]+1+1000]--;
                counter[nums[i]+2+1000]--;
                required[nums[i]+3+1000]++;
            }
            else if(counter[nums[i]+1000]){
                    return false;
            }
        }
        return true;
    }
};