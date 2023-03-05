class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return 0;

        unordered_map<int, vector<int>>adjNodes;
        for(int i=0; i<n; i++){
            adjNodes[arr[i]].push_back(i);   // index
        }

        vector<bool>visited(n, false);

        int ans = 0;
        queue<int>nodeQueue;
        nodeQueue.push(0);
        visited[0] = true;
        while(!nodeQueue.empty()){
            int sz = nodeQueue.size();
            while(sz--){
                int topNode = nodeQueue.front();   // Value
                if(topNode == n-1) return ans;
                // cout<<ans<<' '<<topNode<<endl;
                int topValue = arr[topNode];
                nodeQueue.pop();
                
                for(int i=0; i<adjNodes[topValue].size(); i++){
                    int childNode = adjNodes[topValue][i];    // index
                    if(visited[childNode]) continue;
                    nodeQueue.push(childNode);
                    visited[childNode] = true;
                }

                adjNodes[topValue].clear();

                if(topNode - 1 >= 0 && !visited[topNode - 1]){
                    nodeQueue.push(topNode - 1);
                    visited[topNode - 1] = true;
                }

                if(topNode + 1 < n && !visited[topNode + 1]){
                    nodeQueue.push(topNode + 1);
                    visited[topNode + 1] = true;
                }
            }
            ans++;
        }
        return ans - 1;
    }
};