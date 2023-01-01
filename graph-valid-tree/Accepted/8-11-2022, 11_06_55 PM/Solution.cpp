// https://leetcode.com/problems/graph-valid-tree

class Solution {
public:
    
vector<int>graph[2005];
bool visited[2002]; 

void makeGraph(vector<vector<int>>& edges){
    for(int i=0; i<edges.size(); i++){
      graph[edges[i][0]].push_back(edges[i][1]);
      graph[edges[i][1]].push_back(edges[i][0]);
    }
}

int countNode;

void dfs(int u){
  visited[u] = true;
  countNode++;
  for(int i=0; i<graph[u].size(); i++){
    int v = graph[u][i];
    if(!visited[v]) dfs(v);
  }
}

bool validTree(int n, vector<vector<int>>& edges)
{
    if(edges.size()<n-1 || edges.size()>=n) return false;
    makeGraph(edges);
    countNode = 0;
    dfs(0);
    return countNode == n;
}
};