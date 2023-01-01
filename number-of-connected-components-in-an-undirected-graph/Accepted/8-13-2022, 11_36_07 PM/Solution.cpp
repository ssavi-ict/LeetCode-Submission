// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph

class Solution {
public:
    vector<int>graph[2001];
    bool visited[2001];

    void makeGraph(vector<vector<int>>& edges){
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }

    void dfs(int u){
        visited[u] = true;
        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]) dfs(v);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        makeGraph(edges);

        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i);
                count++;
            }
        }
        return count;
    }
};