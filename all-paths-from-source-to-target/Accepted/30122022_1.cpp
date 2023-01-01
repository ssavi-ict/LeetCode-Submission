class Solution {
public:

    void dfs(int src, int dest, vector<vector<int>> & graph, vector<vector<int>> & ansList, vector<int> & nodes){
        if(src == dest){
            ansList.push_back(nodes);
            return;
        }

        for(int i=0; i<graph[src].size(); i++){
            int child = graph[src][i];
            nodes.push_back(child);
            dfs(child, dest, graph, ansList, nodes);
            nodes.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ansList;
        vector<int>nodes;
        int n = graph.size();
        nodes.push_back(0);
        dfs(0, n-1, graph, ansList, nodes);
        return ansList;
    }
};