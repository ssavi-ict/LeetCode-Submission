// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    
    TreeNode * convertBST(vector<int>&nums, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = convertBST(nums, start, mid-1);
        root->right = convertBST(nums, mid+1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convertBST(nums, 0, size(nums)-1);
    }
};

/*

(nums, 0, 4) | mid = (0+4)/2 = 2, root = 0(2), L (nums, 0, 1), R (nums, 3, 4)
(nums, 0, 1) | mid = (0+1)/2 = 0, root =-10(0), L (nums, 0, -1) = NULL, R (nums, 1, 1)
(nums, 1, 1) | mid = (1+1)/2 = 1, root = -3(1), (nums, 1, 0) = NULL, (nums, 2, 1) =NULL  

(nums, 3, 4) | mid = (3+4)/2 = 3, root =5(3), L(nums, 3, 2) = NULL, R(nums, 4, 4)
(nums, 4, 4) | mid = (4+4)/2 = 4, root = 9(4), L(nums, 5, 3) = NULL, R(nums, 5, 4) = NULL

*/