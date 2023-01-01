// https://leetcode.com/problems/sum-of-distances-in-tree

class Solution {
public:
    int N;

    void find_child_dist(int src, int par, vector<int>&child_dist, vector<int>&nodes, vector<vector<int>>&graph){
        for(int i=0; i<graph[src].size(); i++){
            int child = graph[src][i];
            if(child == par) continue;
            find_child_dist(child, src, child_dist, nodes, graph);
            nodes[src] += nodes[child] + 1;
            child_dist[src] += child_dist[child] + nodes[child] + 1;
        }
    }

    void find_par_dist(int src, int par, vector<int>&child_dist, vector<int>&parent_dist, vector<int>&nodes, vector<vector<int>>&graph){
        if(par != -1){
            parent_dist[src] = parent_dist[par];
            parent_dist[src] += child_dist[par] - child_dist[src] - nodes[src] - 1;
            parent_dist[src] += N - nodes[src] - 1;
        }
        for(int i=0; i<graph[src].size(); i++){
            int child = graph[src][i];
            if(child == par) continue;
            find_par_dist(child, src, child_dist, parent_dist, nodes, graph);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        vector<vector<int>>graph(n+1);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>child_dist(n+1, 0), parent_dist(n+1, 0);
        vector<int>nodes(n+1, 0), sum_of_dist;

        find_child_dist(0, -1, child_dist, nodes, graph);
        find_par_dist(0, -1, child_dist, parent_dist, nodes, graph);

        for(int i=0; i<n; i++){
            sum_of_dist.push_back(child_dist[i] + parent_dist[i]);
        }
        return sum_of_dist;
    }
};