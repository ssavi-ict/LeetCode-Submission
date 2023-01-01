// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count_vowels = 0;
        for(int i=0; i<n; i++){
            char ith_ch = tolower(s[i]);
            if(ith_ch == 'a' || ith_ch == 'e' || ith_ch == 'i' || ith_ch == 'o' || ith_ch == 'u'){
                count_vowels = (i < n/2) ? count_vowels + 1 : count_vowels - 1;
            }
        }
        return count_vowels == 0;
    }
};