// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
public:
    queue<int> first, second;
    MyStack() {
        
    }
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        while(first.size() > 1) {
            second.push(first.front());
            first.pop();
        }
        int top = first.front();
        first.pop();
        
        queue<int> temp = first;
        first = second;
        second = temp;
        
        return top;
    }
    
    int top() {
        int top;
        while(!first.empty()) {
            second.push(first.front());
            top = first.front();
            first.pop();
        }
        queue<int> temp = first;
        first = second;
        second = temp;
        return top;
    }
    
    bool empty() {
        return first.empty();
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