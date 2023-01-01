// https://leetcode.com/problems/path-sum

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
    bool solve(TreeNode * root, int targetSum){
        if(targetSum-root->val == 0 && root->left==NULL && root->right==NULL) return true;
        bool ret = false;
        if(root->left){
            ret = ret or solve(root->left, targetSum - root->val);
        }
        if(root->right){
            ret = ret or solve(root->right, targetSum - root->val);
        }
        return ret;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return solve(root, targetSum);
    }
};