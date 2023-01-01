// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:

    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        
        
        while(i >= 0 || j >= 0) {
            int back = 0;
            while(i >= 0 && (back > 0 || s[i] == '#')) {
                back += s[i] == '#' ? 1 : -1;
                i--;
            }
            
            back = 0;
            while(j >= 0 && (back > 0 || t[j] == '#')) {
                back += t[j] == '#' ? 1 : -1;
                j--;
            }
            
            if(i >= 0 && j >= 0 && s[i] == t[j]) {
                i--; j--;
            }
            else break;
        }
        return i == -1 && j == -1;
    }
};