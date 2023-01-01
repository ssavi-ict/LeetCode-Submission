// https://leetcode.com/problems/leaf-similar-trees

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

    void traverse(TreeNode * root, vector<int> & ints){
        if(root->left == NULL && root->right == NULL){
            ints.push_back(root->val);
            return;
        }
        if(root->left) traverse(root->left, ints);
        if(root->right) traverse(root->right, ints);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>leaf_one, leaf_two;
        traverse(root1, leaf_one);
        traverse(root2, leaf_two);
        return leaf_one == leaf_two;
    }
};