// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    TreeNode * ans, *ansHead;
    void makeflat(TreeNode * root){
        if(!root) return ;
        TreeNode * newNode = new TreeNode(root->val);
        if(!ansHead)
            ans = ansHead = newNode;
        else{
            ans->right = newNode;
            ans = ans->right;
        }
        makeflat(root->left);
        makeflat(root->right);
    }
    
    void flatten(TreeNode* root) {
        if(!root) return ;
        makeflat(root);
        root->left = NULL;
        root->right = ansHead->right;
        root = ansHead;
    }
};