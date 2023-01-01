// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int sz = q1.size();
        while(sz > 1) {
            q1.push(q1.front());
            q1.pop();
            sz--;
        }
    }
    
    int pop() {
        int front = q1.front();
        q1.pop();
        return front;
    }
    
    int top() {
        int front = q1.front();
        return front;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */