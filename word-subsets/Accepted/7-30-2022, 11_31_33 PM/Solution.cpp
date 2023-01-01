// https://leetcode.com/problems/word-subsets

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq[26];
        memset(freq, 0, sizeof(freq));
        
        for(int i=0; i<size(words2); i++){
            int w2count[26] = {0};
            for(int j=0; j<size(words2[i]); j++){
                int idx = words2[i][j]-'a';
                w2count[idx]++;
                freq[idx] = max(freq[idx], w2count[idx]);
            }
        }
        
        words2.clear();
        
        for(int i=0; i<size(words1); i++){
            int w1count[26] = {0};
            int idx;
            for(int j=0; j<size(words1[i]); j++){
                idx = words1[i][j]-'a';
                w1count[idx]++;
            }
            bool flag = true;
            for(int j=0; j<26; j++){
                if(freq[j] > 0 && w1count[j]<freq[j]){
                    flag = false; break;
                }
            }
            if(flag) words2.push_back(words1[i]);
        }
        return words2;
    }
};