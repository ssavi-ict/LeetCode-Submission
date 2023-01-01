// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
private:
    ListNode *curNode;
    TreeNode* getBST(int l, int r){
        if(l > r)
            return NULL;
        int mid = (l + r) / 2;
        TreeNode *left = getBST(l, mid - 1);
        TreeNode *node = new TreeNode(curNode->val);
        curNode = curNode->next;
        node->left = left;
        node->right = getBST(mid + 1, r);
        return node;
    }
        
    int getLength(ListNode *node){
        int length = 0;
        while(node){
            length++;
            node = node->next;
        }
        return length;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        curNode = head;
        return getBST(0, getLength(head) - 1);
    }
};