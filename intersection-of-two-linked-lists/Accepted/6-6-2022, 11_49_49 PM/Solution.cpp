// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * curA = headA;
        ListNode * curB = headB;
        int c1 = 0, c2 = 0;
        while(c1<2 || c2<2){
            if(curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
            if(!curA){
                c1++;
                curA = headB;
            }
            if(!curB){
                c2++;
                curB = headA;
            }
        }
        return nullptr;
    }
};