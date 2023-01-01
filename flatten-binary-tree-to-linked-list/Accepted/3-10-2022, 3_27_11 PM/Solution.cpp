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
    TreeNode* flattenTree(TreeNode* node)
    {
        if(node == NULL)
            return NULL;
        if(node->left == NULL && node->right == NULL)
            return node;
        TreeNode* leftTail = flattenTree(node->left);
        TreeNode* rightTail = flattenTree(node->right);
        
        if(leftTail) {
            leftTail->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        return rightTail == NULL ? leftTail : rightTail;
    }
    
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};