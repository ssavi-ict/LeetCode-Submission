// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode * oddHead = head, *evenHead = head->next;
        ListNode * curOdd = oddHead, *curEven = evenHead;
        head = head->next->next;
        while(true){
            if(!head) break;
            curOdd->next = head;
            head = head->next;
            curOdd = curOdd->next;
            curOdd->next = NULL;


            if(!head) break;
            curEven->next = head;
            head = head->next;
            curEven = curEven->next;
            curEven->next = NULL; 
            
        }
        curEven->next = NULL;
        curOdd->next = evenHead;
        return oddHead;
    }
};