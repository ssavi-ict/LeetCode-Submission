class Solution {
public:

    void bfs(vector<vector<int>> & graph, vector<int> & distance, int src){
        queue<int>Q;
        distance[src] = 0;
        Q.push(src);
        while(!Q.empty()){
            int par = Q.front();
            Q.pop();
            for(int i=0; i<graph[par].size(); i++){
                int child = graph[par][i];
                if(distance[child] != -1) continue;
                distance[child] = distance[par] + 1;
                Q.push(child);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>>graph(n);
        for(int i=0; i<n; i++){
            if(edges[i] == -1) continue;
            graph[i].push_back(edges[i]);
        }
        vector<int>dist_node1(n, -1);
        vector<int>dist_node2(n, -1);
        bfs(graph, dist_node1, node1);
        bfs(graph, dist_node2, node2);

        int minValue = n, ans = -1;
        for(int i=0; i<n; i++){
            if(dist_node1[i] == -1 || dist_node2[i]==-1) continue;
            int max_dist = max(dist_node1[i], dist_node2[i]);
            if(max_dist < minValue){
                minValue = max_dist;
                ans = i;
            }
        }
        return ans;
    }
};