// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

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
    int maxAncestorDiff(TreeNode* root, int MaxSofar = -1, int MinSofar = 100001) {
        if(!root){
            return abs(MaxSofar - MinSofar);
        }
        int ans = 0;
        ans = max(ans, maxAncestorDiff(root->left, max(MaxSofar, root->val), min(MinSofar, root->val)));
        ans = max(ans, maxAncestorDiff(root->right, max(MaxSofar, root->val), min(MinSofar, root->val)));
        return ans;
    }
};