// https://leetcode.com/problems/course-schedule-iii

class Solution {
public:
    struct info{
        int duration, deadline;
    };
    struct comp{
        bool operator()(const info & a, const info & b){
            if(a.deadline == b.deadline){
                return a.duration < b.duration;
            }
            return a.deadline < b.deadline;
        }
    };
    vector<info>cList;
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        for(int i=0; i<n; i++){
            cList.push_back({courses[i][0], courses[i][1]});
        }
        sort(cList.begin(), cList.end(), comp());
        int curr = 0;
        priority_queue<int>pq;
        for(int i=0; i<n; i++){
            if(curr + cList[i].duration <= cList[i].deadline){
                curr += cList[i].duration;
                pq.push(cList[i].duration);
            }
            if(!pq.empty() && pq.top() > cList[i].duration){
                curr -= pq.top();
                pq.pop();
                curr += cList[i].duration;
                pq.push(cList[i].duration);
            }
        }
        return pq.size();
    }
};