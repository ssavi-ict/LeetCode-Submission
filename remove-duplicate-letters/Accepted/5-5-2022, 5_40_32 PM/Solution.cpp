// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> lastOccurence;
        unordered_map<char, bool> seen;
        
        stack<char> stack;
        for(int i = 0; i < s.size(); i++)
            lastOccurence[s[i]]  = i;
        
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(!seen[c]) {
                while(!stack.empty() && stack.top() > c && lastOccurence[stack.top()] > i) {
                    seen[stack.top()] = false;
                    stack.pop();
                }
                seen[c] = true;
                stack.push(c);
            }
        }
        
        string result;
        while(!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};