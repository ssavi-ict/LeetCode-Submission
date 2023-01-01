// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:

    int visit(int src, vector<vector<int>> & graph, vector<bool> & visited){
        visited[src] = true;
        queue<int>node_q; node_q.push(src);
        int count = 1;
        
        while(!node_q.empty()){
            int top_node = node_q.front();
            node_q.pop();
            for(int i=0; i<graph[top_node].size(); i++){
                int child = graph[top_node][i];
                if(!visited[child] && child != top_node){
                    visited[child] = true;
                    count++;
                    node_q.push(child);
                }
            }
        }
        return count;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = rooms.size();
        vector<bool>visited(1001, false);
        return visit(0, rooms, visited) == n;
    }
};