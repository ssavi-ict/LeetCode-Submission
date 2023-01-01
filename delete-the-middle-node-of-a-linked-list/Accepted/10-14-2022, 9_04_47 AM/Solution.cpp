// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode * slow = head, * fast = head;
        bool flag = false;
        while(fast && fast->next){
            fast = fast->next;
            if(fast->next) fast = fast->next;
            if(flag) slow = slow->next;
            flag = true;
        }
        slow->next = slow->next->next;
        return head;
    }
};