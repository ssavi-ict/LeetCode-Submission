// https://leetcode.com/problems/delete-node-in-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * cur = node;
        while(cur->next){
            cur->val = cur->next->val;
            if(cur->next->next == NULL){
                cur->next = NULL;
                break;
            }
            cur = cur->next;
        }
        
    }
};