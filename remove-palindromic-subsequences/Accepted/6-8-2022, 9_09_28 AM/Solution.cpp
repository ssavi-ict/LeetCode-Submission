// https://leetcode.com/problems/remove-palindromic-subsequences

class Solution {
public:
    int removePalindromeSub(string s) {
        int len = s.size();
        for(int i=0; i<len/2; i++){
            if(s[i]!=s[len-i-1]){
                return 2;
            }
        }
        return 1;
    }
};