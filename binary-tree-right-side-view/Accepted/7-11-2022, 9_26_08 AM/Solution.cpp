// https://leetcode.com/problems/binary-tree-right-side-view

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
    
    void solve(TreeNode * root, vector<int>&ans, int lvl){
        if(root == NULL) return;
        ans[lvl] = root->val;
        if(root->left){
            solve(root->left, ans, lvl+1);
        }
        if(root->right){
            solve(root->right, ans, lvl+1);
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans(105, -1);
        solve(root, ans, 0);
        for(auto it=ans.begin(); it!=ans.end(); ++it){
            if(*it==-1){
                ans.erase(it, ans.end());
                break;
            }
        }
        return ans;
    }
};