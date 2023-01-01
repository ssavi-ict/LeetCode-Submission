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
    
    void solve(TreeNode * root, int sLen, int & ans){
        if(root->left){
            int dist = root->left->val - root->val;
            sLen = (dist == 1) ? sLen + 1: 1;
            ans = max(ans, sLen);
            solve(root->left, sLen, ans);
        }
        if(root->right){
            int dist = root->right->val - root->val;
            sLen = (dist == 1) ? sLen + 1: 1;
            ans = max(ans, sLen);
            solve(root->right, sLen, ans);
        }
    }
    
    int longestConsecutive(TreeNode* root) {
        int ans = 1;
        solve(root, 1, ans);
        return ans;
    }
};