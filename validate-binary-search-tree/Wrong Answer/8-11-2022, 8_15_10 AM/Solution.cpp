// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool ret = true;
        if(root->left){
            ret = ret & (root->val > root->left->val) & isValidBST(root->left);
        }
        if(root->right){
            ret = ret & (root->val < root->right->val) & isValidBST(root->right);
        }
        return ret;
    }
};

/*



*/