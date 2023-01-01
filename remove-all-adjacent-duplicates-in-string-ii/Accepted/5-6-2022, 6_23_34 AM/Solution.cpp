// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int> > counts;
        
        for(char c: s) {
            if(!counts.empty() && counts.back().first == c) {
                counts.back().second++;
            }
            else {
                counts.push_back({c, 1});
            }
            if(counts.back().second == k) {
                counts.pop_back();
            }
        }
        
        string res;
        for(auto item: counts) {
            res += string(item.second, item.first);
        }
        return res;
        
    }
};