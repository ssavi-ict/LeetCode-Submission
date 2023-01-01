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
        vector<int>out;
        stack<TreeNode *>st;
        
        while(root){
            st.push(root);
            root = root->left;
        }
        
        while(st.size() > 0){
            TreeNode *curNode = st.top();
            st.pop();
            out.push_back(curNode->val);
            if(curNode->right){
                TreeNode *right = curNode->right;
                while(right){
                    st.push(right);
                    right = right->left;
                }
            }
        }
        
        return out;
    }
};