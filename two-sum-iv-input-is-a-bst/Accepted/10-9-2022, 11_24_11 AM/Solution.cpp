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

    void recurse(TreeNode * root, vector<int>&numbers){
        if(root == NULL) return;
        recurse(root->left, numbers);
        numbers.push_back(root->val);
        recurse(root->right, numbers);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>numbers;
        recurse(root, numbers);
        int left = 0, right = size(numbers) - 1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == k) return true;
            if(sum < k) left++;
            else right--;
        }
        return false;
    }
};