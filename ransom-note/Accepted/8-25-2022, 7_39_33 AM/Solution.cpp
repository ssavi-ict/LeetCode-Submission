// https://leetcode.com/problems/ransom-note

class Solution {
public:
    
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26];
        memset(freq, 0, sizeof(freq));
        int n = size(magazine);
        for(int i=0; i<n; i++){
            freq[magazine[i] - 'a']++;
        }
        
        n = size(ransomNote);
        for(int i=0; i<n; i++){
            freq[ransomNote[i] - 'a']--;
            if(freq[ransomNote[i] - 'a'] < 0) return false;
        }
        return true;
    }
};