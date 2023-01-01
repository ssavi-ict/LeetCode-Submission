// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        int left = 0, right = 0, length = 0;
        string word = "";
        while(right <= size){
            if(right == size || s[right] == ' '){
                if(word.size() > 0){
                    s += " ";
                    reverse(word.begin(), word.end());
                    s += word;
                    word = "";
                    length++;
                }
                left = ++right;
            }
            else{
                word +=s[right++];
                length++;
            }
        }
        reverse(s.begin(), s.end());
        return s.substr(0, length - 1);
    }
};