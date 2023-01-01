// https://leetcode.com/problems/palindrome-linked-list

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
    
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode * current_node = head;
        int total_node = 0;
        while(current_node){
            current_node = current_node->next;
            total_node++;
        }
        
        current_node = head;
        ListNode * prev_node = NULL, *nextNode = NULL;
        int temp_total = 0;
        bool is_mid_passed = false;
        
        while(temp_total<total_node){
            if(temp_total < total_node/2){
                nextNode = current_node->next;
                current_node->next = prev_node;
                prev_node = current_node;
                current_node = nextNode;
            }
            else{
                if(total_node%2==1 && !is_mid_passed){
                    current_node = current_node->next;
                    temp_total++;
                    is_mid_passed = true;
                }
                
                if(current_node->val!=prev_node->val) return false;
                current_node = current_node->next;
                prev_node = prev_node->next;
            }
            temp_total++;
        }
        return true;
    }
};