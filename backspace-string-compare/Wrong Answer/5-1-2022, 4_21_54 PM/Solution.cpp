// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    string getActual(string s) {
        string sActual;
        for(auto c: s) {
            if(c == '#' && !sActual.empty())
                sActual.pop_back();
            sActual.push_back(c);
        }
        return sActual;
    }
    bool backspaceCompare(string s, string t) {
        
        string sActual = getActual(s);
        string tActual = getActual(t);
        return sActual == tActual;
        
    }
};