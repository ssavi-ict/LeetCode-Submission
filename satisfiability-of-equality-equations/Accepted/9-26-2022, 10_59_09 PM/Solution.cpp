// https://leetcode.com/problems/satisfiability-of-equality-equations

class Solution {
public:
    
    int findParent(int node, vector<int>& parent){
        if(parent[node] == node) return node;
        parent[node] = findParent(parent[node], parent);
        return parent[node];
    }
    
    void unionNode(int a, int b, vector<int> & parent){
        int parent_a = findParent(a, parent);
        int parent_b = findParent(b, parent);
        if(parent_a != parent_b){
            parent[parent_a] = parent_b;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26);
        for(int i=0; i<26; i++) parent[i] = i;
        
        int n = equations.size();
        for(int i=0; i<n; i++){
            if(equations[i][1] == equations[i][2]){
                int left = equations[i][0] - 'a';
                int right = equations[i][3] - 'a';
                unionNode(left, right, parent);
            }
        }
        
        for(int i=0; i<n; i++){
            if(equations[i][1] != equations[i][2]){
                int left = equations[i][0] - 'a';
                int right = equations[i][3] - 'a';
                int left_parent = findParent(left, parent);
                int right_parent = findParent(right, parent);
                if(left_parent == right_parent) return false;
            }
        }
        return true;
    }
};