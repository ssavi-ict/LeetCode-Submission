// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    
    vector<int>graph[200005];
    bool visited[200005];
    
    bool dfs(int src, int dest){
        visited[src] = true;
        if(src == dest) return true;
        bool ret = false;
        for(int i=0; i<size(graph[src]); i++){
            int v = graph[src][i];
            if(!visited[v]){
                ret = ret | dfs(v, dest);
            }
        }
        return ret;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0; i<size(edges); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        memset(visited, false, sizeof(visited));
        return dfs(source, destination);
    }
};