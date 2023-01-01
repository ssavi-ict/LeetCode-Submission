// https://leetcode.com/problems/binary-tree-level-order-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode * root, int lvl, vector<vector<int>> &ans, int & mxlvl){
        if(!root) return;
        mxlvl = max(lvl, mxlvl);
        ans[lvl].push_back(root->val);
        solve(root->left, lvl+1, ans, mxlvl);
        solve(root->right, lvl+1, ans, mxlvl);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans(2001);
        int mx = -1;
        solve(root, 0, ans, mx);
        if(mx == -1) 
            ans.resize(0);
        else
            ans.resize(mx+1);
        return ans;
    }
};