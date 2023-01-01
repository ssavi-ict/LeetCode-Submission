// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int has[130];
    int lengthOfLongestSubstring(string s) {
        int len = s.length(), cnt = 0, ans = 0, tot = 1;
        memset(has, 0, sizeof(has));
        for(int i=0; i<len; i++){
            if(has[s[i]] != tot){
                has[s[i]] = tot;
                cnt++;
            }
            else{
                cnt = 1;
                tot++;
                has[s[i]] = tot;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};