// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    unordered_map<TreeNode*, bool>mymap;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * cur = root;
        while(cur!=p){
            mymap[cur] = true;
            cur = (p->val < cur->val) ? cur->left : cur->right;
        }
        mymap[cur] = true;
        
        cur = root;
        TreeNode * ans = root;
        while(cur!=q){
            if(mymap[cur]) ans = cur;
            cur = (q->val < cur->val) ? cur->left : cur->right;
        }
        if(mymap[cur]) ans = cur;
        return ans;
    }
};