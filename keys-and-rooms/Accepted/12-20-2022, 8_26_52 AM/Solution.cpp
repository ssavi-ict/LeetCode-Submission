// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:

    int visit(int src, vector<vector<int>> & graph, vector<bool> & visited){
        visited[src] = true;
        int count = 1, child_sz = graph[src].size();
        for(int i=0; i<child_sz; i++){
            int next = graph[src][i];
            if(!visited[next] && next != src){
                count += visit(next, graph, visited);
            }
        }
        return count;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(1001, false);
        return visit(0, rooms, visited) == n;
    }
};