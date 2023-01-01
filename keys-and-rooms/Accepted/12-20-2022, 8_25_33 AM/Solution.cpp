// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:

    int visit(int src, vector<vector<int>> & graph, vector<bool> & visited){
        visited[src] = true;
        int count = 1, child_sz = graph[src].size();
        for(int i=0; i<child_sz; i++){
            int next = graph[src][i];
            if(!visited[next]){
                count += visit(next, graph, visited);
            }
        }
        return count;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>>graph(1001, vector<int>(1001));
        int n = rooms.size();
        for(int i=0; i<n; i++){
            int rsize = rooms[i].size();
            for(int j=0; j<rsize; j++){
                if(i == rooms[i][j]) continue;
                graph[i].push_back(rooms[i][j]);
            }
        }
        vector<bool>visited(1001, false);
        
        return visit(0, graph, visited) == n;
    }
};