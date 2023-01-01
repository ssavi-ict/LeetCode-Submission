// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode * current = root;
        vector<int>ans;
        while(current){
            if(current->left == NULL){
                ans.push_back(current->val);
                current = current->right;
            }
            else{
                TreeNode * inorder_pred = current->left;
                while(inorder_pred->right && inorder_pred->right!=current) inorder_pred = inorder_pred->right;
                if(inorder_pred->right == NULL){
                    inorder_pred->right = current;
                    current = current->left;
                }
                else{
                    inorder_pred->right = NULL;
                    ans.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return ans;
    }
};

/*

stack = 2, 3
ans = 5, 1, 3 2

*/