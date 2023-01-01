// https://leetcode.com/problems/count-complete-tree-nodes

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
    int getDepth(TreeNode * root){
        if(!root->left) return 0;
        return 1 + getDepth(root->left);
    }

    bool checkMidNodeOnLastLevel(TreeNode * root, int midLeaf, int depth){
        int left = 1, right = (1 << depth);
        while(depth--){
            int mid = left + ((right - left) >> 1);
            if(midLeaf >= mid){
                left = mid + 1;
                root = root->right;
            }
            else{
                right = mid - 1;
                root = root->left;
            }
        }
        return root != NULL;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int depth = getDepth(root);
        // cout<<"Depth "<<depth<<endl;
        if(depth == 0) return 1;
        
        int plevel_node = (1 << depth) - 1;
        int leftLeaf = 1, rightLeaf = (1<<depth) - 1;
        while(leftLeaf <= rightLeaf){
            int midLeaf = leftLeaf + ((rightLeaf - leftLeaf) >> 1);
            if(checkMidNodeOnLastLevel(root, midLeaf, depth)) leftLeaf = midLeaf + 1;
            else rightLeaf = midLeaf - 1;
        }
        return plevel_node + leftLeaf;
    }
};