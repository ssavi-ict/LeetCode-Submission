// https://leetcode.com/problems/remove-palindromic-subsequences

class Solution {
public:
    int removePalindromeSub(string s) {
        int a = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a') a++;
        }
        int b = s.size() - a;
        char lfor = (a>=b) ? 'b' : 'a';
        int sub_len = (a>=b) ? a : b;
        
        int cnt = 1;
        for(int i=0; i<s.size(); i++){
            if(s[i]==lfor && s[s.size()-i-1]==lfor){
                sub_len++;
            }
        }
        if(sub_len==s.size()) return cnt;
        return cnt + 1;
    }
};