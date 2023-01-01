// https://leetcode.com/problems/make-the-string-great

class Solution {
public:
    bool isUpper(char c){
        return (c >= 'A' && c<='Z');
    }
    
    char toLower(char c){
        return (isUpper(c) == true ? (c + 32) : c);
    }
    
    
    bool doesStaisfy(char & first, char & second){
        if(isUpper(first) && isUpper(second)) return false;
        if(!isUpper(first) && !isUpper(second)) return false;
        first = toLower(first), second = toLower(second);
        if(first != second) return false;
        return true;
    }
    
    string makeGood(string s) {
        stack<char>greatStack;
        int n = s.size();
        for(int i=n-1; i>=0; i--){
            bool needToInsert = true;
            
            if(!greatStack.empty()){
                char top_element = greatStack.top();
                if(doesStaisfy(top_element, s[i])){
                    greatStack.pop();
                    needToInsert = false;
                }
            }
            if(needToInsert) greatStack.push(s[i]);
        }
        
        s = "";
        while(!greatStack.empty()) s += greatStack.top(), greatStack.pop();
        return s;
    }
};