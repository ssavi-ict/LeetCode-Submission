// https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void solve(Node *root, vector<vector<int>>&ans, int lvl){
        if(lvl == ans.size()){
            vector<int>new_vec;
            ans.push_back(new_vec);
        }
        ans[lvl].push_back(root->val);
        
        for(int i=0; i<root->children.size(); i++){
            solve(root->children[i], ans, lvl+1);
        }
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        solve(root, ans, 0);
        return ans;
    }
};