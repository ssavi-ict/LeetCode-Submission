// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    
    void solve(TreeNode * root, int vert, vector<vector<int>>&ans){
        ans[vert].push_back(root->val);
        if(root->left){
            solve(root->left, vert-1, ans);
        }
        if(root->right){
            solve(root->right, vert+1, ans);
        }
    }
    
    void get_level(TreeNode * root, int lvl, int & start_level, int & end_level){
        if(root->left){
            start_level = min(start_level, lvl-1);
            get_level(root->left, lvl-1, start_level, end_level);
        }
        
        if(root->right){
            end_level = max(end_level, lvl+1);
            get_level(root->right, lvl+1, start_level, end_level);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int start_level = 0, end_level = 0;
        get_level(root, 0, start_level, end_level);
        
        // cout<<start_level<<' '<<end_level<<endl;
        vector< vector<int> >ans(end_level-start_level+1);
        solve(root, -start_level, ans);
        for(int i=0; i<ans.size(); i++){
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};