// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    
    int sumLevel[10001], countLevel[10001];
    
    void solve(TreeNode * root, int lvl){
        if(!root) return;
        sumLevel[lvl] += root->val;
        countLevel[lvl] += 1;
        solve(root->left, lvl+1);
        solve(root->right, lvl+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        solve(root, 0);
        vector<double>ans;
        for(int i=0; countLevel[i] && sumLevel[i];i++){
            ans.push_back((sumLevel[i]*1.0)/countLevel[i]);
        }
        return ans;
    }
};