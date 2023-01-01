// https://leetcode.com/problems/partition-list

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
    ListNode* partition(ListNode* head, int x) {
        ListNode * list1 = NULL, *list1head = NULL;
        ListNode * list2 = NULL, *list2head = NULL;
        while(head){
            ListNode * node = new ListNode(head->val);
            if(head->val < x){
                if(!list1head){
                    list1 = list1head = node;
                }
                else{
                    list1->next = node; list1 = list1->next;
                }
            }
            else{
                if(!list2head){
                    list2 = list2head = node;
                }
                else{
                    list2->next = node; list2 = list2->next;
                }
            }
            head = head->next;
        }
        
        if(list2head){
            if(!list1)
                list1head = list2head;
            else
                list1->next = list2head;
        }
        return list1head;
    }
};