// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
public:
    
    int totalNode, currentNode;
    struct ListNode{
        int val;
        ListNode * next, * prev;
        ListNode(int x) : val(x), next(NULL), prev(NULL){}
    };
    
    ListNode * head,* tail;
    
    MyCircularQueue(int k) {
        totalNode = k;
        currentNode = 0;
    }
    
    bool enQueue(int value) {
        if(currentNode == totalNode) return false;
        if(currentNode == 0){
            head = new ListNode(value);
            tail = head;
        }
        else{
            ListNode * newNode = new ListNode(value);
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
            tail->next = head;
            head->prev = tail;
        }
        currentNode++;
        return true;
    }
    
    bool deQueue() {
        if(currentNode == 0) return false;
        
        if(currentNode == 1){
            head = head->next;
            tail = head;
        }
        else{
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        currentNode--;
        return true;
    }
    
    int Front() {
        if(currentNode == 0) return -1;
        return head->val;
    }
    
    int Rear() {
        if(currentNode == 0) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return currentNode == 0;
    }
    
    bool isFull() {
        return currentNode == totalNode;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */