// https://leetcode.com/problems/count-univalue-subtrees

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
    int cnt;

    void solve(TreeNode * root){
        if(!root) return;
        if(!root->left && !root->right){
            cnt++;
        }
        else{
            solve(root->left);
            solve(root->right);
            if(root->left && root->val == root->left->val){
                if(!root->right || (root->right && root->val == root->right->val)){
                    cnt++;
                }
                else if(root->right && (root->right && root->val != root->right->val)){
                    root->val = INT_MAX;
                }
            }
            else if(root->right && root->val == root->right->val){
                if(!root->left || (root->left && root->val == root->left->val)){
                    cnt++;
                }
                else if(root->left && (root->left && root->val != root->left->val)){
                    root->val = INT_MAX;
                }
            }
            else{
                if(root->left){
                    root->val = INT_MAX;;
                }
                if(root->right){
                    root->val = INT_MAX;;
                }
            }
        }
    }

    int countUnivalSubtrees(TreeNode* root) {
        cnt = 0;
        solve(root);
        return cnt;
    }
};