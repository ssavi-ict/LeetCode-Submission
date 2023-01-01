// https://leetcode.com/problems/path-sum

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
    void getPathSum(TreeNode * root, int targetSum, bool & ans){
        int value = root->val;
        // cout<<targetSum<<' '<<value<<endl;
        if(targetSum - value == 0 && (!root->left && !root->right)){
            ans = ans or 1;
        }
        
        if(root->left){
            getPathSum(root->left, targetSum - value, ans);
        }
        if(root->right){
            getPathSum(root->right, targetSum - value, ans);
        }
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        bool ans = false;
        getPathSum(root, targetSum, ans);
        return ans;
    }
};