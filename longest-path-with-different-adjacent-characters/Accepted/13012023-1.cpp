class Solution {
public:

    int solve(int node, vector<vector<int>>&graph, int parent, int & answerLength, string & assigned){
        int maxOne = 0, maxTwo = 0;
        for(int i=0; i<graph[node].size(); i++){
            int child = graph[node][i];
            if(child == parent) continue;
            
            int length = solve(child, graph, node, answerLength, assigned);
            length = (assigned[node] == assigned[child]) ? 0 : length + 1;

            if(length >= maxTwo){
                maxOne = maxTwo, maxTwo = length;
            }
            else if(length >= maxOne){
                maxOne = length;
            }
        }
        answerLength = max(answerLength, maxOne + maxTwo);
        return max(maxOne, maxTwo);
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>>graph(n);
        for(int i=0; i<n; i++){
            if(parent[i] != -1){
                graph[parent[i]].push_back(i);
                // graph[i].push_back(parent[i]);
            }
        }
        int answerLength = 0;
        solve(0, graph, 0, answerLength, s);
        return answerLength + 1;
    }
};