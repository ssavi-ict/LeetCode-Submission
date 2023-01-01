// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    int counter;
    
    void solve(TreeNode * root, int max_so_far, int nodeVal){
        if(nodeVal >= max_so_far){
            counter++;
        }
        if(root->left){
            max_so_far = max(max_so_far,root->left->val );
            solve(root->left, max_so_far, root->left->val);
        }
        
        if(root->right){
            max_so_far = max(max_so_far,root->right->val );
            solve(root->right, max_so_far, root->right->val);
        }
    }
    
    int goodNodes(TreeNode* root) {
        solve(root, root->val, root->val);
        return counter;
    }
};