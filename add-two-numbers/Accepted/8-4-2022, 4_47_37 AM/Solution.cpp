// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * newHead = NULL, *newCur = NULL;
        int carry = 0;
        while(l1 || l2){
            int sum = carry;
            if(l1){
                sum += l1->val; l1 = l1->next;
            }
            if(l2){
                sum += l2->val; l2 = l2->next;
            }
            
            if(!newHead){
                newHead = new ListNode(sum%10); 
                newCur = newHead;
            }
            else{
                ListNode * newNode = new ListNode(sum%10);
                newCur->next = newNode;
                newCur = newCur->next;
            }
            carry = sum / 10;
        }
        while(carry){
            ListNode * newNode = new ListNode(carry%10);
            newCur->next = newNode;
            newCur = newCur->next;
            carry = carry / 10;
        }
        return newHead;
    }
};