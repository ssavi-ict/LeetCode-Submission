// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = size(s), ans = 0;
        int appear[58];
        memset(appear, -1, sizeof(appear));
        queue<char>myQ;
        
        int left = 0, right = 0;
        for(right = 0; right<n; right++){
            if(appear[s[right]-'A'] == -1){
                myQ.push(s[right]);
            }
            
            
            if(myQ.front() == s[right]){
                myQ.pop(); myQ.push(s[right]);
            }
            
            if(myQ.size() > 2){
                ans = max(ans, right - left);
                left = appear[myQ.front()-'A']  + 1;
                appear[myQ.front()-'A'] = -1;
                myQ.pop();
            }
            appear[s[right]-'A'] = right;
        }
        ans = max(ans, right - left);
        return ans;
    }
};