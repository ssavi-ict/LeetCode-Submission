// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii

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
    
    struct data{
        int incr, decr;
    };
    typedef data DATA;
    
    int maxSeq;
    
    DATA solve(TreeNode * root, DATA current){
        if(root->left){
            DATA left = solve(root->left, {1,1});
            if(root->val + 1 == root->left->val){
                current.incr = max(left.incr + 1, current.incr);
            }
            else if(root->val - 1 == root->left->val){
                current.decr = max(left.decr + 1, current.decr);
            }
        }
        if(root->right){
            DATA right = solve(root->right, {1,1});
            if(root->val + 1 == root->right->val){
                current.incr = max(right.incr + 1, current.incr);
            }
            
            if(root->val - 1 == root->right->val){
                current.decr = max(right.decr + 1, current.decr);
            }
        }
        maxSeq = max(maxSeq, current.incr + current.decr - 1);
        return current;
    }
    
    int longestConsecutive(TreeNode* root) {
        maxSeq = 1;
        solve(root, {1,1});
        return maxSeq;
    }
};