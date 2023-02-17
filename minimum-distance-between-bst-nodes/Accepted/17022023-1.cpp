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
    
    void solve(TreeNode * root, vector<int> & values){
        if(root ==  NULL) return;
        solve(root->left, values);
        values.push_back(root->val);
        solve(root->right, values);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int>values;
        solve(root, values);
        int ans = INT_MAX;
        for(int i=1; i<values.size(); i++){
            ans = min(ans, abs(values[i] - values[i-1]));
        }
        return ans;
    }
};