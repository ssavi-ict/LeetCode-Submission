// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    unordered_map<int, int>mymap;
    int preid = 0;
    
    TreeNode * solve(vector<int>&preorder, int start, int end){
        if(start > end) return nullptr;
        int value = preorder[preid];
        TreeNode * node = new TreeNode;
        node->val = value;
        preid++;
        node->left = solve(preorder, start, mymap[value]-1);
        node->right = solve(preorder, mymap[value]+1, end);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inSize = size(inorder);
        int preSize = size(preorder);
        for(int i=0; i<inSize; i++){
            mymap[inorder[i]]= i;
        }
        return solve(preorder, 0, preSize-1);
    }
};