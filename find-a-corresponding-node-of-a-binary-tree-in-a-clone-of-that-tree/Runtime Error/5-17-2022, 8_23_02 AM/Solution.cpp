// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool flag = false;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!flag && original->val==cloned->val && cloned->val==target->val){
            flag = true;
            return cloned;
        }
        TreeNode * ans;
        if(original->left) ans = getTargetCopy(original->left, cloned->left, target);
        if(original->right) ans = getTargetCopy(original->right, cloned->right, target);
        return ans;
    }
};