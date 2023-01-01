// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *>mystack;
        
        while(root){
            mystack.push(root);
            root = root->left;
        }
        
        vector<int>ans;
        while(mystack.size() > 0){
            TreeNode *current = mystack.top();
            mystack.pop();
            ans.push_back(current->val);
            if(current->right){
                TreeNode * go_left = current->right;
                while(go_left){
                    mystack.push(go_left);
                    go_left = go_left->left;
                }
            }
        }
        return ans;
    }
};

/*

stack = 2, 3
ans = 5, 1, 3 2

*/