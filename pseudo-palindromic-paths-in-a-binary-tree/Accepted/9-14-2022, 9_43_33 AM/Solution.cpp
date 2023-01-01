// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

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
    int ans;
    void solvePal(TreeNode * root, int mask){
        if(!root->left && !root->right){
            int cnt = 0;
            int new_mask = (mask ^ (1 << (root->val - 1)));
            for(int i=1; i<=9; i++){
                if(new_mask & (1 << (i-1))) cnt++;
            }
            if(cnt <= 1){
                // cout<<new_mask<<endl;
                ans++;
            }
        }
        if(root->left){
            solvePal(root->left, (mask ^ (1 << (root->val - 1))));
        }
        if(root->right){
            solvePal(root->right, (mask ^ (1 << (root->val - 1))));
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        solvePal(root, 0);
        return ans;
    }
};