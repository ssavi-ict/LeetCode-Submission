// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    
    bool isVowel(char c){
        if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int start = 0, end = s.size() - 1;
        while(start < end){
            if(!isVowel(s[start])) start++;
            if(!isVowel(s[end])) end--;
            
            if(isVowel(s[start]) && isVowel(s[end])){
                swap(s[start], s[end]);
                start++, end--;
            }
        }
        return s;
    }
};