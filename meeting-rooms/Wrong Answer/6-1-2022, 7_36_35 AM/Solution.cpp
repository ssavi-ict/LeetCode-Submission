// https://leetcode.com/problems/meeting-rooms

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>mergedIntervals;
        
        for(auto interval: intervals){
            if(mergedIntervals.size() == 0 || 
               mergedIntervals.back()[1] < interval[0]){
                mergedIntervals.push_back(interval);
            }
            else{
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[0]);
            }
        }
        
        return intervals.size() == mergedIntervals.size();
    }
};