class Solution {
public:

    vector<int>solve(int node, vector<vector<int>> &graph, vector<int> & ans, string & labels, int parent){
        vector<int>countFreq(26, 0);
        
        for(int i=0; i<graph[node].size(); i++){
            int child = graph[node][i];
            if(child == parent) continue;
            vector<int>childFreq = solve(child, graph, ans, labels, node);
            for(int j=0; j<26; j++){
                countFreq[j] += childFreq[j];
            }
        }
        countFreq[labels[node]-'a']++;
        ans[node] = countFreq[labels[node]-'a'];
        return countFreq;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>graph(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int>ans(n, 0);
        solve(0, graph, ans, labels, 0);
        return ans;
    }
};