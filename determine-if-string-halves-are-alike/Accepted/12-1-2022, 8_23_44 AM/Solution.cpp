// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        vector<int>count_vowels(n, 0);
        for(int i=0; i<n; i++){
            char ith_ch = tolower(s[i]);
            if(i) count_vowels[i] =  count_vowels[i-1];
            if(ith_ch == 'a' || ith_ch == 'e' || ith_ch == 'i' || ith_ch == 'o' || ith_ch == 'u'){
                count_vowels[i]++;
            }
        }
        return count_vowels[n/2 - 1] == (count_vowels[n-1] - count_vowels[n/2 - 1]);
    }
};