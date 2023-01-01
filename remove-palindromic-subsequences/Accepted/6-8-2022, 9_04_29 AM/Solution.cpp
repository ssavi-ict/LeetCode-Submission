// https://leetcode.com/problems/remove-palindromic-subsequences

class Solution {
public:
    int removePalindromeSub(string s) {
        int sub_len = 0; int cnt = 1;
        for(int i=0; i<s.size(); i++){
            if(s[i] == s[0]) sub_len++;
            else if(s[i]!=s[0] && s[i]==s[s.size()-i-1]){
                sub_len++;
            }
        }
        return (sub_len==s.size())? cnt :cnt + 1;
    }
};