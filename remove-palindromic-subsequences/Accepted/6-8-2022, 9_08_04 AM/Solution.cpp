// https://leetcode.com/problems/remove-palindromic-subsequences

class Solution {
public:
    int removePalindromeSub(string s) {
        int len = s.size();
        for(int i=0; i<s.size(); i++){
            if(s[i]!=s[s.size()-i-1]){
                len--;
            }
        }
        return (len==s.size())?1:2;
    }
};