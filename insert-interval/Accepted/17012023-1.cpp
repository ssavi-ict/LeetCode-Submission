class Solution {
public:

    void insertInterval(int start_x, int start_y, vector<vector<int>> & ans, bool & flag){
        if(start_x != -1 && start_y != -1 && !flag){
            ans.push_back({start_x, start_y});
            flag = true;
        }
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int start_x = INT_MAX, start_y= -1;
        bool flag = false;
        for(int i=0; i<intervals.size(); i++){
            if(newInterval[0] > intervals[i][1]){
                if(!flag) insertInterval(start_x, start_y, ans, flag);
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1]){
                if(!flag) insertInterval(start_x, start_y, ans, flag);
                ans.push_back(intervals[i]);
            }
            else{
                start_x = min(start_x, min(newInterval[0], intervals[i][0]));
                start_y = max(start_y, max(newInterval[1], intervals[i][1]));
            }
        }
        if(!flag) {
            insertInterval(start_x, start_y, ans, flag);
            if(!flag) ans.push_back(newInterval);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};