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
        ListNode * first, *second;
        first = head, second = head;
        int temp = n;
        while(first->next){
            if(n<=0){
                second = second->next;
            }
            n--;
            first = first->next;
        }
        if(second!=head || n==0){
            // cout<<second->val<<endl;
            second->next = second->next->next;
        }
        else
            head = head->next;
        return head;
    }
};

/*

1->2->3->4->5  | 1 | 5
4  3  2  1  0


*/