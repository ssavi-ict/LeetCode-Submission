// https://leetcode.com/problems/palindrome-permutation

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int>frequency(26, 0);
        int n = s.size();
        for(int i=0; i<n; i++){
            frequency[s[i]-'a']++;
        }
        
        int odd = 0;
        for(char i='a'; i<='z'; i++){
            if(frequency[i-'a']%2 == 1){
                odd++;
            }
        }
        
        return odd <= 1;
    }
};