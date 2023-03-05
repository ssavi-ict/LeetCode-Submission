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

    string solve(TreeNode * root, unordered_map<string, int> & frequency, vector<TreeNode*> & ans){
        if(root == NULL) return "*";
        string left = solve(root->left, frequency, ans);
        string right = solve(root->right, frequency, ans);

        string str = left + "-" + right + "-" + to_string(root->val);
        if(frequency[str] == 1) ans.push_back(root);
        frequency[str]++;
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int>frequency;
        vector<TreeNode*> answer;
        solve(root, frequency, answer);
        return answer;
    }
};