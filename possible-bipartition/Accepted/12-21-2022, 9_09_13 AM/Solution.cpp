// https://leetcode.com/problems/possible-bipartition

class Solution {
public:

    bool dfs(int src, vector<vector<int>>&graph, vector<int>&visited, int color){
        visited[src] = color;
        bool status = true;
        for(int i=0; i<graph[src].size(); i++){
            int child = graph[src][i];
            if(visited[child] != -1 && visited[child] == color) status = status & false;
            if(visited[child] == -1) status = status & dfs(child, graph, visited, color ^ 1);
        }
        return status;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(n+1);
        int dis_size = dislikes.size();
        for(int i=0; i<dis_size; i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int>visited(n+1, -1);
        for(int i=1; i<=n; i++){
            if(visited[i] == -1){
                if(!dfs(i, graph, visited, 0)) return false;
            }
        }
        return true;
    }
};