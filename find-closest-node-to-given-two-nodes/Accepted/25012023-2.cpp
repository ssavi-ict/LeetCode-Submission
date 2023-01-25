class Solution {
public:

    void bfs(vector<int> & graph, vector<int> & distance, int src){
        queue<int>Q;
        distance[src] = 0;
        while(true){
            int next = graph[src];
            if(next == -1 || distance[next] != -1){
                break;
            }
            distance[next] = distance[src] + 1;
            src = next;
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dist_node1(n, -1);
        vector<int>dist_node2(n, -1);
        bfs(edges, dist_node1, node1);
        bfs(edges, dist_node2, node2);

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