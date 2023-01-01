// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:
    vector<int>graph[100005];
    int tCount = 0;
    bool visited[100005];
    int dtime[100005], low[100005], parent[100005];
    
    void bridge(int u, int n, vector<vector<int>>& connections){
        dtime[u] = low[u] = tCount++;
        visited[u] = true;
        // int child = 0;
        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                parent[v] = u;
                // child++;
                bridge(v, n, connections);
                low[u] = min(low[v], low[u]);
                if(low[v] > dtime[u]){
                    connections.push_back({u,v});
                }
            }
            else if(parent[u]!=v){
                low[u] = min(low[u], dtime[v]);
            }
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0], v = connections[i][1];
            // cout<<"Hi"<<endl;
            graph[u].push_back(v);
            graph[v].push_back(u);
            
        }
        connections.clear();
        parent[0] = -1;
        bridge(0, n, connections);
        return connections;
    }
};