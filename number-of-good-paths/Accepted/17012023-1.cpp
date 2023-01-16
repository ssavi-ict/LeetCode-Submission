class Solution {
public:

    int getParent(int node, vector<int> & parent){
        if(parent[node] == node) return node;
        return parent[node] = getParent(parent[node], parent);
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), m = edges.size(), ans = n;
        vector<int>parent(n), countNodes(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;

        sort(edges.begin(), edges.end(), [&](const vector<int>&a, const vector<int>&b){
            return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);
        });
        for(int i=0; i<m; i++){
            int startNode = edges[i][0], endNode = edges[i][1];
            int parentStartNode = getParent(startNode, parent), parentEndNode = getParent(endNode, parent);
            if(vals[parentStartNode] == vals[parentEndNode]){
                ans += (countNodes[parentStartNode] * countNodes[parentEndNode]);
                parent[parentStartNode] = parentEndNode;
                countNodes[parentEndNode] += countNodes[parentStartNode];
            }
            else if(vals[parentStartNode] > vals[parentEndNode]){
                parent[parentEndNode] = parentStartNode;
            }
            else{
                parent[parentStartNode] = parentEndNode;
            }
        }
        return ans;
    }
};