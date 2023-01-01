// https://leetcode.com/problems/reverse-linked-list

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
class Solution {
public:
    ListNode* reverseList(ListNode* curr, ListNode* previous) {
        if(curr->next == NULL) {
            curr->next = previous;
            return curr;
        }
        ListNode* next = curr->next;
        curr->next = previous;
        return reverseList(next, curr);
        
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        return reverseList(head, NULL);
        
    }
};