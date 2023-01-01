// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int has[130];
    int lengthOfLongestSubstring(string s) {
        int len = s.length(), ans = 0;
        memset(has, 0, sizeof(has));
        int left = 0, right = 0;
        while(right < len){
            has[s[right]]++;
            while(has[s[right]] > 1){
                has[s[left]]--; left++;
            }
            ans = max(ans, right - left+1);
            right++;
        }
        return ans;
    }
};