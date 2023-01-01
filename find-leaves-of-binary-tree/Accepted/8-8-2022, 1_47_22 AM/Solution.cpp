// https://leetcode.com/problems/find-leaves-of-binary-tree

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
    
    int solve(TreeNode * root, vector< vector<int>>&ans){
        if(!root) return 0;
        int lvl = max(solve(root->left, ans), solve(root->right, ans)) + 1;
        if(lvl > ans.size()) ans.push_back(vector<int>());
        ans[lvl-1].push_back(root->val);
        return lvl;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector< vector<int>> ans;
        solve(root, ans);
        return ans;
    }
};

/*

solve(1, ans) -> max(solve(2), solve(3))
max(solve(2), solve(3)) -> solve(2) -> max(solve(4), solve(5))
solve(4) = 0 + 1 = 1 | solve(5) = 0 + 1 = 1 =>  ans[0]-> 4, 5, 3
solve(2) = max(solve(4), solve(5)) + 1 = 1 + 1 = 2 => ans[1]->2
solve(3) = max(0, 0) + 1 = 1 => ans[0]-> 4, 5, 3
solve(1) = max(2, 1) + 1 = 3 => ans[2]->1
*/