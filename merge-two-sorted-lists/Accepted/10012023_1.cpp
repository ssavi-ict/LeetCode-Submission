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
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        if(!first) return second;
        if(!second) return first;
        ListNode * ans, * ansCur, * curFirst, *curSecond;
        if(first->val <= second->val){
            curFirst = first->next;
            curSecond = second;
            ans = ansCur = first;
        }
        else{
            curFirst = first;
            curSecond = second->next;
            ans = ansCur = second;
        }
        
        while(curFirst || curSecond){
            if(!curSecond){
                ansCur->next = curFirst;
                break;
            }
            else if(!curFirst){
                ansCur->next = curSecond;
                break;
            }
            else if(curFirst->val <= curSecond->val){
                ansCur->next = curFirst;
                curFirst = curFirst->next;
            }
            else{
                ansCur->next = curSecond;
                curSecond = curSecond->next;
            }
            ansCur = ansCur->next;
        }
    
        return ans;
    }
};