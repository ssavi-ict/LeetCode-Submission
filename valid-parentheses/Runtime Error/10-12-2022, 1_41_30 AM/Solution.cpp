// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1) return false;
        stack<char>mystack;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                mystack.push(s[i]);
            }
            else{
                char top = mystack.top();
                if(top == '(' && s[i] == ')'){
                    mystack.pop();
                }
                else if(top == '[' && s[i] == ']'){
                    mystack.pop();
                }
                else if(top == '{' && s[i] == '}'){
                    mystack.pop();
                }
                else{
                    mystack.push(s[i]);
                }
            }
        }
        return mystack.size() == 0;
    }
};