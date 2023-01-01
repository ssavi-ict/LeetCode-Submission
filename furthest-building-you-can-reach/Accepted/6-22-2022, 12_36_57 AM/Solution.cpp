// https://leetcode.com/problems/furthest-building-you-can-reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int sum = 0, i;
        for(i=1; i<heights.size(); i++){
            if(heights[i]<=heights[i-1]) continue;
            int jump = heights[i] - heights[i-1];
            pq.push(jump);
            if(pq.size() > ladders){
                int top = pq.top();
                sum = sum + top;
                pq.pop();
            }
            if(sum>bricks) break;
        }
        return i-1;
    }
};