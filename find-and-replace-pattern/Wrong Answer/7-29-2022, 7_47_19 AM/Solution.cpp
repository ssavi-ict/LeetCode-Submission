// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int psz = size(pattern);
        vector<int>pcount(psz, 0);
        pcount[0] = 1;
        for(int i=1; i<psz; i++){
            pcount[i] = (pattern[i] == pattern[i-1]) ? pcount[i-1] + 1: 1;
        }
        
        int t_word = size(words);
        vector<string>ans;
        for(int i=0; i<t_word; i++){
            bool flag = true;
            int count = 1;
            for(int j=1; j<psz; j++){
                count = (words[i][j] == words[i][j-1])? count + 1 : 1;
                if(count!=pcount[j]){
                    flag = false; break;
                }
            }
            
            if(flag) ans.push_back(words[i]);
        }
        return ans;
    }
};