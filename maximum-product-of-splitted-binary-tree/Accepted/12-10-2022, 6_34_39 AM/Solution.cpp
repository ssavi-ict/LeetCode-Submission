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

    int solve(TreeNode * root, vector<int> & sums){
        if(!root) return 0;
        int left = solve(root->left, sums);
        int right = solve(root->right, sums);
        if(left > 0) sums.push_back(left);
        if(right > 0) sums.push_back(right);
        if((left + right + root->val) > 0)sums.push_back(left + right + root->val);
        return (left + right + root->val); 
    }

    int maxProduct(TreeNode* root) {
        vector<int>sums;
        int total = solve(root, sums);
        long long maxVal = 0;
        for(int i=0; i<sums.size(); i++){
            long long newVal = (long long) sums[i] * (long long)(total - sums[i]);
            maxVal = max(maxVal, newVal);
        }
        return maxVal % MOD;
    }
};