// https://leetcode.com/problems/first-letter-to-appear-twice

class Solution {
public:
    int cnt[26];
    char repeatedCharacter(string s) {
        char x;
        for(int i=0; i<s.size(); i++){
            cnt[s[i]-'a']++;
            if(cnt[s[i]-'a'] == 2){
                x = s[i]; break;
            }
        }
        return x;
    }
};