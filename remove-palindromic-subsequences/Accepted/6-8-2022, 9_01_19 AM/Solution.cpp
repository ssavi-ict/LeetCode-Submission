// https://leetcode.com/problems/remove-palindromic-subsequences

class Solution {
public:
    int removePalindromeSub(string s) {
        int a = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a') a++;
        }
        int sub_len = a; int cnt = 1; char lfor = 'b';
        for(int i=0; i<s.size(); i++){
            if(s[i]==lfor && s[s.size()-i-1]==lfor){
                sub_len++;
            }
        }
        if(sub_len==s.size()) return cnt;
        return cnt + 1;
    }
};