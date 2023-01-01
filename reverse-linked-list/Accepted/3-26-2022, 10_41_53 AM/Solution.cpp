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

/*
1->2->3->4->5

2->1
    
*/



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *node = NULL;
        ListNode *curNode = head;
        
        while(curNode){
            ListNode *nxt = curNode->next;
            curNode->next = node;
            node = curNode;
            curNode = nxt;
        }
        
        return node;
    }
};