// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        TreeNode * lSide = lowestCommonAncestor(root->left, p, q);
        TreeNode * rSide = lowestCommonAncestor(root->right, p, q);
        if(lSide && rSide) return root;
        if(lSide) return lSide;
        return rSide;
    }
};