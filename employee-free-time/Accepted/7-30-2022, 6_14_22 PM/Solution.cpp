// https://leetcode.com/problems/employee-free-time

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;
    Interval() {}
    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval>ans;
        map<int,int>mp;
        int n = schedule.size();
        for( int i = 0 ; i < n ; i++){
            int m = schedule[i].size();
            for(int j = 0 ; j < m; j++){
                mp[schedule[i][j].start]++;
                mp[schedule[i][j].end]--;
            }
        }
        int working = 0 ;
        for(auto it : mp)
        {
            working += it.second;
            if(!working) ans.push_back(Interval(it.first,0));
            if(working && ans.size() && !ans.back().end ) ans.back().end = it.first;
        }
        if(!ans.empty()) ans.pop_back();
        return ans;
        //TC: O(nlogm)
        //SC: O(summation of all m*2)
    }
};