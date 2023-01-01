// https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {
public:
    int getWeight(vector<int>& startPoint, vector<int>& endPoint) {
        return abs(startPoint[0]-endPoint[0]) +
            abs(startPoint[1] - endPoint[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int totalCost = 0;
        
        map<int, bool> visited;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        heap.push({0,0});
        
        while(visited.size() != n) {
            pair<int,int> topElement = heap.top();
            heap.pop();
            
            int currNode = topElement.second;
            int weight = topElement.first;
            
            if(visited.count(currNode))
                continue;
            
            totalCost += weight;

            visited[currNode] = true;
            for(int nextNode = 0; nextNode < n; ++nextNode) {
                if(visited.count(nextNode))
                    continue;
                int nextWeight = getWeight(points[currNode], points[nextNode]);
                heap.push({nextWeight, nextNode});
            }
        }
        return totalCost;
        
    }
};