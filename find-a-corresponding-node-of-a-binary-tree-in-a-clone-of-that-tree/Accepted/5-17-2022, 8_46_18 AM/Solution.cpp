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
    TreeNode * ans;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original->val==cloned->val && cloned->val==target->val){
            //cout<<"Hi"<<endl;
            ans = cloned;
            return ans;
        }
        
        if(ans) return ans;
        
        if(original->left){
            ans = getTargetCopy(original->left, cloned->left, target);
        }
        if(original->right){
            ans = getTargetCopy(original->right, cloned->right, target);
        }
        return ans;
    }
};