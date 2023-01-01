// https://leetcode.com/problems/shortest-distance-to-target-color

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector< vector<int> >store(4);
        for(int i=0; i<size(colors); i++){
            store[colors[i]].push_back(i);
        }
        
        vector<int>ans;
        for(int i=0; i<size(queries); i++){
            int num = queries[i][1], key = queries[i][0];
            int dist = -1;
            if(store[num].size() > 0){
                int lidx = upper_bound(store[num].begin(), store[num].end(), key) - store[num].begin();
                // cout<<lidx<<endl;
                if(lidx == store[num].size()) lidx--;
                dist = abs(store[num][lidx] - key);
                if(lidx - 1>=0) dist = min(dist, abs(key-store[num][lidx-1]));
            }
            ans.push_back(dist);
        }
        return ans;
    }
};