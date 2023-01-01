// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
    int freq[22][26];
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0; i<size(words); i++){
            int mapped[26];
            int already_mapped[26];
            
            bool flag = true;
            memset(mapped, -1, sizeof(mapped));
            memset(already_mapped, -1, sizeof(already_mapped));
            
            for(int j=0; j<size(words[i]); j++){
                int sidx = words[i][j] - 'a';
                int pidx = pattern[j] -'a';
                if(mapped[pidx]==-1){
                    if(already_mapped[sidx]==-1){
                        mapped[pidx] = sidx;
                        already_mapped[sidx] = pidx;
                    }
                    else{
                        flag = false; break;
                    }
                }
                else if(mapped[pidx]==sidx && already_mapped[sidx]==pidx){
                    ;
                }
                else{
                    flag = false;
                }
            }
            
            if(flag){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};