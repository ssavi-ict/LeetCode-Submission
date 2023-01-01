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
    
    TreeNode* helper(int preI, int preJ, vector<int>&pre,int inI, unordered_map<int,int>&mp)
    {
       if(preI>preJ) return NULL;
       TreeNode* root = new TreeNode(pre[preI]);
       int leftCount = mp[pre[preI]]-inI;
       root->left = helper(preI+1,preI+leftCount,pre,inI,mp);
       root->right = helper(preI+leftCount+1,preJ,pre,mp[pre[preI]]+1, mp);
       return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size(), n = inorder.size();
        unordered_map<int,int>mp;
        for( int i = 0 ; i < m; i++) mp[inorder[i]] = i;
        return helper(0, m-1,preorder,0, mp);
        //TC: O(n)
        //SC: O(n)
    }
};

    /*  //inorder = left -> root -> right
        //preorder= root -> left -> right
        Input: preorder = [3,  9,8,10  20,15,7], inorder = [8,9,10,3,15,20,7]
  
 step -1:
           Inorder
    [left]  [root]    [right]
    8,9,10     3       15,20,7
            
            
           Preorder
    [left]  [root]    [right]
    9,8,10     3       20,15,7
            

 step -2:
                Inorder
    [left]       [root]      [right]
[l] [root]   [r]          [l] [root]   [r] 
8     9    10      3       15   20       7     
            
            
           Preorder
    [left]       [root]      [right]
[l] [root]   [r]          [l] [root]   [r] 
9     8    10      3       20   15       7 
                    
                    
                 3
               /   \
              9    20         
            / \    / \
          8   10  15  7 */
        
        