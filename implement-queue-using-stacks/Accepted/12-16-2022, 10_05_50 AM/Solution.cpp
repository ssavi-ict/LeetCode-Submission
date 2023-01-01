// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
public:

    stack<int>base, reverse;
    MyQueue() {
        
    }
    
    void push(int x) {
        base.push(x);
    }

    void insert_on_reverse(){
        while(!base.empty()){
            reverse.push(base.top());
            base.pop();
        }
    }
    
    int pop() {
        if(reverse.empty()){
            insert_on_reverse();
        }
        int top = reverse.top();
        reverse.pop();
        return top;
    }
    
    int peek() {
        if(reverse.empty()){
            insert_on_reverse();
        }
        return reverse.top();
    }
    
    bool empty() {
        return (base.empty() && reverse.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */