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
    
    long long sumLevel[10001], countLevel[10001];
    int mxLvl;
    
    void solve(TreeNode * root, int lvl){
        if(!root) return;
        mxLvl = max(lvl, mxLvl);
        sumLevel[lvl] += root->val;
        countLevel[lvl] += 1;
        solve(root->left, lvl+1);
        solve(root->right, lvl+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        solve(root, 0);
        vector<double>ans;
        for(int i=0;i<=mxLvl;i++){
            ans.push_back((sumLevel[i]*1.0)/countLevel[i]);
        }
        return ans;
    }
};