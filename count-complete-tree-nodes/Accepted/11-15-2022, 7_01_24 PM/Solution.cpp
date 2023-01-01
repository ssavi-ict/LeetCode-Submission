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

    int getHeight(TreeNode * root){
        if(!root->left) return 0;
        return 1 + getHeight(root->left);
    }
    bool checkPathExist(TreeNode * root, int leafMid, int height){
        int lo = 0, hi = (1 << height) - 1;
        while(height--){
            int mid = lo + ((hi - lo) >> 1);
            if(leafMid <= mid){
                root = root->left;
                hi = mid - 1;
            }
            else{
                root = root->right;
                lo = mid + 1;
            }
        }
        return root != NULL;
    }

    int countNodes(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!root) return 0;
        int height = getHeight (root);
        if(height == 0) return 1;

        int leafLeft = 1, leafRight = (1<<height) - 1;
        while(leafLeft <= leafRight){
            int leafMid = leafLeft + (leafRight - leafLeft)/2;
            if(checkPathExist(root, leafMid, height)) leafLeft = leafMid + 1;
            else leafRight = leafMid - 1;
        }

        return (1 << height) + (leafLeft - 1);
    }
};