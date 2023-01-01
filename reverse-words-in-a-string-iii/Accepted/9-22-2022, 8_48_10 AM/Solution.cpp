// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        s = "";
        while(ss >> word){
            if(s[0]!='\0') s += ' ';
            reverse(word.begin(), word.end());
            s += word;
        }
        return s;
    }
};