class Solution {
public:

    int dfs(vector<vector<int>> & graph, int src, int parent, long long & ans, int seats){
        int count = 1;
        for(int i=0; i<graph[src].size(); i++){
            int child = graph[src][i];
            if(child != parent){
                count  += dfs(graph, child, src, ans, seats);
            }
        }

        long long fuel = (count / seats);
        if(count % seats) fuel++;
        if(src > 0) ans += fuel;

        return count;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>>graph(n);
        for(int i=0; i<n-1; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        long long ans = 0;
        dfs(graph, 0, -1, ans, seats);
        return ans;
    }
};