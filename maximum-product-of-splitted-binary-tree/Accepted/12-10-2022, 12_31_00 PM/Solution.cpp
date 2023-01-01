// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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
    const int MOD = 1e9 + 7;
    long long maxVal = 0;

    long long solve(TreeNode * root, bool type, long long total){
        if(!root) return 0;
        long long left = solve(root->left, type, total);
        long long right = solve(root->right, type, total);
        if(type){
            maxVal = max(maxVal, left * (total - left));
            maxVal = max(maxVal, right * (total - right));
            long long newSum =(left + right + root->val);
            maxVal = max(maxVal, newSum * (total - newSum));
        }
        return (left + right + root->val); 
    }

    int maxProduct(TreeNode* root) {
        long long total = solve(root, false, 0);
        solve(root, true, total);
        return maxVal % MOD;
    }
};