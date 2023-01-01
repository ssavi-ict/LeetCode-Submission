// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence

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
    
    void solve(TreeNode * root, int sLen, int & ans){
        // cout<<root->val<<' '<<sLen<<endl;
        if(root->left){
            int dist = root->left->val - root->val;
            if(dist == 1){
                ans = max(ans, sLen + 1);
                solve(root->left, sLen + 1, ans);
            }
            else{
                ans = max(ans, 1);
                solve(root->left, 1, ans);
            }
        }
        if(root->right){
            int dist = root->right->val - root->val;
            if(dist == 1){
                ans = max(ans, sLen + 1);
                solve(root->right, sLen + 1, ans);
            }
            else{
                ans = max(ans, 1);
                solve(root->right, 1, ans);
            }
            
        }
    }
    
    int longestConsecutive(TreeNode* root) {
        int ans = 1;
        solve(root, 1, ans);
        return ans;
    }
};