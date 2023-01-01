// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>frequency(65, 0);
        int n = s.size();
        for(int i=0; i<n; i++){
            frequency[s[i]-'A']++;
        }
        
        int ans = 0;
        bool center = false;
        for(char i='A'; i<='Z'; i++){
            if(frequency[i-'A']%2 == 0){
                ans += frequency[i-'A'];
            }
            else{
                ans += (frequency[i-'A'] - 1);
                center = true;
            }
        }
        
        for(char i='a'; i<='z'; i++){
            if(frequency[i-'A']%2 == 0){
                ans += frequency[i-'A'];
            }
            else{
                ans += (frequency[i-'A'] - 1);
                center = true;
            }
        }
        
        if(center) ans++;
        
        return ans;
    }
};