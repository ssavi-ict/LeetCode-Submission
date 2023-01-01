// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<pair<int,int> > info;
        for(int index = 0; index < nums.size(); index++) {
            info.push_back({nums[index], index});
        }
        sort(info.begin(), info.end());
        int leftMin = nums.size();
        int rightMax = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            pair<int,int> currInfo = info[i];
            if(currInfo.second != i) {
                leftMin = min(leftMin, currInfo.second);
                rightMax = max(rightMax, i);
            }
        }
        if(leftMin <= rightMax) {
            return rightMax - leftMin + 1;
        }
        return 0;
        
    }
};