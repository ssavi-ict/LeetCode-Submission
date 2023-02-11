class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>distance(n, -1);
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        vector<vector<pair<int, int>>>graph(n);

        for(int i=0; i<redEdges.size(); i++){
            graph[redEdges[i][0]].push_back({redEdges[i][1], 0});
        }

        for(int i=0; i<blueEdges.size(); i++){
            graph[blueEdges[i][0]].push_back({blueEdges[i][1], 1});
        }

        queue<pair<int, int>>nodeQueue;
        nodeQueue.push({0, -1});
        distance[0] = 0;
        visited[0][0] = visited[0][1] = true;
        int step = 0;

        while(!nodeQueue.empty()){
            int sz = nodeQueue.size();
            while(sz--){
                auto front = nodeQueue.front();
                int node = front.first; int color = front.second;
                nodeQueue.pop();

                for(int i=0; i<graph[node].size(); i++){
                    auto child = graph[node][i];
                    if(child.second != color && !visited[child.first][child.second]){
                        if(distance[child.first] == -1){
                            distance[child.first] = step + 1;
                        }
                        nodeQueue.push(child);
                        visited[child.first][child.second] = true;
                    }
                }
            }
            step++;
        }
        return distance;
    }
};