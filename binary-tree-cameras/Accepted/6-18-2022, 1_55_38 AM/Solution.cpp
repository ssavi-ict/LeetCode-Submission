// https://leetcode.com/problems/binary-tree-cameras

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
    int ans;
    int solve(TreeNode * root){
        if(!root->left && !root->right){
            root->val = 1;
            return 0;
        }
        int res = 0;
        int l = 2, r = 2;
        if(root->left){
            res = res + solve(root->left);
            l = root->left->val;
        }
        if(root->right){
            res = res + solve(root->right);
            r = root->right->val;
        }
        
        if(l==1 || r==1){
            root->val = 3;
            return res + 1;
        }
        
        if(l==3 || r==3){
            root->val = 2;
            return res;
        }
        root->val = 1;
        return res;
    }
    int minCameraCover(TreeNode* root) {
        int ans = solve(root);
        return root->val==1?ans+1:ans;
    }
};