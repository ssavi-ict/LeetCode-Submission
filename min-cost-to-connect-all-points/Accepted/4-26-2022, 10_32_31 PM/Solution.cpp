// https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {
public:
    int getWeight(vector<int>& startPoint, vector<int>& endPoint) {
        return abs(startPoint[0]-endPoint[0]) +
            abs(startPoint[1] - endPoint[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int totalWeight = 0;
        
        map<int, bool> visited;
        vector<int> minWeight(n, INT_MAX);
        minWeight[0] = 0;
        
        
        while(visited.size() != n) {
            int currNode = -1;
            int currMinEdge = INT_MAX;
            
            for(int node = 0; node < n; node++) {
                if(visited.count(node))
                    continue;
                if(minWeight[node] < currMinEdge) {
                    currNode = node;
                    currMinEdge = minWeight[node];
                }
            }
            totalWeight += currMinEdge;
            visited[currNode] = true;

            for(int nextNode = 0; nextNode < n; ++nextNode) {
                if(visited.count(nextNode))
                    continue;
                int nextWeight = getWeight(points[currNode], points[nextNode]);
                minWeight[nextNode] = min(minWeight[nextNode], nextWeight);
            }
        }
        return totalWeight;
        
    }
};