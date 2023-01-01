// https://leetcode.com/problems/linked-list-cycle-ii

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *curNode = head;
        ListNode *slow = head;
        ListNode *fast = head;
        bool cycleFound = false;
        
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = (fast->next)->next;
            if(slow == fast){
                cycleFound = true;
                break;
            }
        }
        
        if(!cycleFound)
            return NULL;
        
        while(curNode && curNode != slow){
            curNode = curNode->next;
            slow = slow->next;
        }
        
        return curNode;
    }
};