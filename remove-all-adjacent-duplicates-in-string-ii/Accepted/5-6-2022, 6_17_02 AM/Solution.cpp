// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int,int> > info;
        
        for(char c: s) {
            if(!info.empty() && info.back().first == c) {
                info.back().second++;
            }
            else {
                info.push_back({c, 1});
            }
            if(info.back().second >= k) {
                info.back().second -= k;
                if(info.back().second == 0)
                    info.pop_back();
            }
        }
        
        string res;
        for(auto item: info) {
            for(int i = 0; i < item.second; i++)
                res.push_back(item.first);
        }
        return res;
        
    }
};