// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence

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
    
    // int ans;
    void solve(TreeNode * root, int len, int &ans){
        if(!root) return;
        if(root->left){
            int diff = root->left->val - root->val == 1? len + 1 : 1;
            ans = max(ans, diff);
            solve(root->left, diff, ans);
        }
        if(root->right){
            int diff = root->right->val - root->val == 1? len + 1 : 1;
            ans = max(ans, diff);
            solve(root->right, diff, ans);
        }
    }
    
    int longestConsecutive(TreeNode* root) {
        int ans = 1;
        solve(root, 1, ans);
        return ans;
    }
};