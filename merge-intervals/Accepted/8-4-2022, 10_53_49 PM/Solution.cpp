// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector< pair<int, int> >segment;
        for(int i=0; i<size(intervals); i++){
            segment.push_back(make_pair(intervals[i][0], intervals[i][1]));
        }
        sort(segment.begin(), segment.end());
        vector<vector<int>>ans;
        int start=segment[0].first, end=segment[0].second;
        for(int i=1; i<size(segment); i++){
            if(segment[i].first<=end){
                end = max(end, segment[i].second);
            }
            else{
                vector<int>temp;
                temp.push_back(start); temp.push_back(end);
                ans.push_back(temp);
                start = segment[i].first;
                end = segment[i].second;
            }
        }
        vector<int>temp;
        temp.push_back(start); temp.push_back(end);
        ans.push_back(temp);
        return ans;
    }
};