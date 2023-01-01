// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size(), ans = 0;
        set<char>myset;
        int counter[128] = {0};
        
        int left = 0, right = 0;
        for(right=0; right<n; right++){
            myset.insert(s[right]);
            counter[s[right]]++;
            while(myset.size() > 2){
                ans = max(ans, right - left);
                if(counter[s[left]] == 1){
                    auto it = myset.find(s[left]);
                    myset.erase(it);
                }
                counter[s[left]]--;
                left++;
            }
        }
        ans = max(ans, right - left);
        return ans;
    }
};