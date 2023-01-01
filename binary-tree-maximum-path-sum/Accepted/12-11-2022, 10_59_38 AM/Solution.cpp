// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int solve(TreeNode * root, int & ans){
        if(!root) return 0;
        int left = max(solve(root->left, ans), 0);
        int right = max(solve(root->right, ans), 0);
        ans = max(ans, left + right + root->val);
        return max(left+root->val, right+root->val);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};