// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends

class Solution {
public:
    vector<int>graph[101];
    vector<int>cost[101];
    bool visited[101];

    vector<pair<int, pair<int, int>>>edges;
    int ans;
    int cnt;

    void dfs(int u){
        visited[u] = true;
        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                cnt++;
                ans = max(ans, cost[u][i]);
                dfs(v);
            }
        }
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        for(int i=0; i<logs.size(); i++){
            edges.push_back(make_pair(logs[i][0], make_pair(logs[i][1], logs[i][2])));
        }
        sort(edges.begin(), edges.end());

        for(int i=0; i<edges.size(); i++){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int w = edges[i].first;
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
            
            memset(visited, false, sizeof(visited));
            ans = 0;
            cnt = 0;
            dfs(0);
            
            if(cnt==n-1)break;
        }

      // Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4

        return (cnt==n-1)? ans : -1;
    }
};