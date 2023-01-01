// https://leetcode.com/problems/deepest-leaves-sum

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
    
    int cMxLvl, ans;
    
    void solve(TreeNode * root, int lvl){
        if(root->left == NULL && root->right==NULL){
            if(lvl > cMxLvl){
                ans = root->val;
                cMxLvl = lvl;
            }
            else if(lvl == cMxLvl){
                ans = ans + root->val;
            }
            return;
        }
        
        if(root->left) solve(root->left, lvl+1);
        if(root->right) solve(root->right, lvl+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        cMxLvl = ans = 0;
        solve(root, 0);
        return ans;
    }
};