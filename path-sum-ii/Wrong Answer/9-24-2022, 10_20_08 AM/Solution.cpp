// https://leetcode.com/problems/path-sum-ii

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
    
    void getPathSum(TreeNode * root, vector<vector<int>> & answer, vector<int> & tmp, int targetSum){
        if(root==NULL){
            if(targetSum == 0){
                answer.push_back(tmp);
            }
            return;
        }
        
        int value = root->val;
        tmp.push_back(value);
        
        getPathSum(root->left, answer, tmp, targetSum - value);
        if(root->right)
            getPathSum(root->right, answer, tmp, targetSum - value);
       
        tmp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>answer;
        vector<int>tmp;
        getPathSum(root, answer, tmp, targetSum);
        return answer;
    }
};