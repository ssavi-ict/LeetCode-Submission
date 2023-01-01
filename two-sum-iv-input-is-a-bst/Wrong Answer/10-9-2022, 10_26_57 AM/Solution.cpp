// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    unordered_map<int, int>numbers;

    void recurse(TreeNode * root){
        if(root == NULL) return;
        numbers[root->val]++;
        recurse(root->left);
        recurse(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        numbers.clear();
        recurse(root);
        for(auto it=numbers.begin(); it!=numbers.end(); ++it){
            int left = k - it->first;
            if(left!=it->first && numbers[left] > 0){
                return true;
            }
            
        }
        return false;
    }
};