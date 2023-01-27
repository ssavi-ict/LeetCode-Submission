class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>graph(n);
        for(int i=0; i<flights.size(); i++){
            graph[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }
        vector<int>cost(n, INT_MAX);
        queue<pair<int, int>>myQ;
        int countStop = 0;
        cost[src] = 0;
        myQ.push({src, 0});

        while(!myQ.empty() && countStop <= k){
            int qSize = myQ.size();
            while(qSize--){
                auto topNode = myQ.front();
                myQ.pop();
                for(int i=0; i<graph[topNode.first].size(); i++){
                    int child = graph[topNode.first][i].first;
                    int childCost =  topNode.second + graph[topNode.first][i].second;
                    // cout<<child<<' '<<childCost<<endl;
                    if(childCost < cost[child]){
                        cost[child] = childCost;
                        // cout<<topNode.first<<' '<<child<<' '<<cost[child]<<endl;
                        myQ.push({child, childCost});
                    }
                }
            }
            countStop++;
        }
        return cost[dst] ==  INT_MAX? -1: cost[dst];
    }
};