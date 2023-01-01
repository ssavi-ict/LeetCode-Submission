// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>vec;
        ListNode * cur = head;
        while(cur){
            vec.push_back(cur->val);
            cur = cur->next;
        }
        left--, right--;
        while(left < right){
            swap(vec[left], vec[right]);
            left++, right--;
        }
        
        ListNode * curr, * newH;
        curr = newH = new ListNode(vec[0]);
        int idx = 1;
        while(idx<size(vec)){
            // ListNode * node = new ListNode(vec[idx++]);
            curr->next = new ListNode(vec[idx++]);
            curr = curr->next;
        }
        return newH;
    }
};