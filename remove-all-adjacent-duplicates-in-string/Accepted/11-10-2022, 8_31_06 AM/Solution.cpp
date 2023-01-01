// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        int s_size = s.size();
        stack<char>charStack;
        for(int i=0; i<s_size; i++){
            bool popped = false;
            while(!charStack.empty() && charStack.top() == s[i]){
                charStack.pop();
                popped = true;
            }
            if(!popped){
                charStack.push(s[i]);
            }
        }
        s = "";
        while(!charStack.empty()) s += charStack.top(), charStack.pop();
        reverse(s.begin(), s.end());
        return s;
    }
};