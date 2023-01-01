// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int idx[26];
    int firstUniqChar(string s) {
        memset(idx, -1, sizeof(idx));
        int ans = s.size();
        for(int i=0; i<s.size(); i++){
            if(idx[s[i]-'a']!=-1) idx[s[i]-'a'] = INT_MAX;
            else idx[s[i]-'a'] = i;
        }
        for(int i=0; i<26; i++){
            if(idx[i]!=-1) ans = min(ans, idx[i]);
        }
        return ans==s.size()?-1:ans;
    }
};