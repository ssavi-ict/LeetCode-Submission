class Solution {
public:

    void findMin(int node, vector<vector<int>>&graph, int & ans, vector<int>&mapChar){
        if(mapChar[node] != -1) {
            ans = min(ans, node);
            return;
        }
        ans = min(ans, node);
        mapChar[node] = ans;
        for(int i=0; i<graph[node].size(); i++){
            int child = graph[node][i];
            // if(mapChar[child] != -1) continue;
            findMin(child, graph, ans, mapChar);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>>graph(26);
        int n = s1.size(), m = baseStr.size();
        for(int i=0; i<n; i++){
            graph[s1[i]-'a'].push_back(s2[i]-'a');
            graph[s2[i]-'a'].push_back(s1[i]-'a');
        }

        vector<int>mapChar(26, -1);
        for(int i=0; i<26; i++){
            if(mapChar[i] == -1){
                int ans = i;
                findMin(i, graph, ans, mapChar);
                // mapChar[i] = ans;
            }
        }
        
        for(int i=0; i<m; i++){
            baseStr[i] = mapChar[baseStr[i] - 'a'] + 'a';
        }
        return baseStr;
    }
};