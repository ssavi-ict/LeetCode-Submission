// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    string getActual(string s) {
        string ans;
        for(auto c: s) {
            if(c != '#')
                ans.push_back(c);
            else if(!ans.empty())
                ans.pop_back();
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        
        string sActual = getActual(s);
        string tActual = getActual(t);
        return sActual == tActual;
        
    }
};