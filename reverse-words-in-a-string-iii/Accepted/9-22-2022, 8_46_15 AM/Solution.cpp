// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans = "";
        while(ss >> word){
            if(ans[0]!='\0') ans += ' ';
            reverse(word.begin(), word.end());
            ans += word;
        }
        return ans;
    }
};