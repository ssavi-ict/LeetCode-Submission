// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int nodes = 0;
        ListNode * cur = head, * newNode = head;
        while(cur){
            cur = cur->next;
            nodes++;
            
            if(!cur){
                int toDel = nodes - n;  // 30 - 30
                if(toDel == 0){
                  head = head->next;
                }
                else{
                  for(int i=0; i<toDel-1; i++){
                    newNode = newNode->next; // i = 0, 
                  }
                  newNode->next = newNode->next->next;
                }
            }
        }
        return head;
    }
};