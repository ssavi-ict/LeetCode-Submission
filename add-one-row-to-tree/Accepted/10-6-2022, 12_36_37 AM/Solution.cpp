// https://leetcode.com/problems/add-one-row-to-tree

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

    void solve(TreeNode * root, int val, int depth, int direction, TreeNode * pre){
        if(depth == 1){
            TreeNode * newNode = new TreeNode(val);
            if(direction == 1){
                newNode->left = root;
                pre->left = newNode;
            }
            if(direction == 2){
                newNode->right = root;
                pre->right = newNode;
            }
            return;
        }
        if(!root) return;
        solve(root->left, val, depth-1, 1, root);
        solve(root->right, val, depth-1, 2, root);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode * newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        solve(root, val, depth, 0, root);
        return root;
    }
};

