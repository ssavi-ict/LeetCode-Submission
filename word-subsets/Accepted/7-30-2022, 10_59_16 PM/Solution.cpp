// https://leetcode.com/problems/word-subsets

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq[26];
        memset(freq, 0, sizeof(freq));
        
        for(int i=0; i<size(words2); i++){
            vector<int>w2count(26,0);
            for(int j=0; j<size(words2[i]); j++){
                w2count[words2[i][j]-'a']++;
                freq[words2[i][j]-'a'] = max(freq[words2[i][j]-'a'], w2count[words2[i][j]-'a']);
            }
        }
        
        vector<string>ans;
        
        for(int i=0; i<size(words1); i++){
            vector<int>w1count(26,0);
            for(int j=0; j<size(words1[i]); j++){
                w1count[words1[i][j]-'a']++;
            }
            bool flag = true;
            for(int j=0; j<26; j++){
                if(freq[j] > 0 && w1count[j]<freq[j]){
                    flag = false; break;
                }
            }
            if(flag) ans.push_back(words1[i]);
        }
        return ans;
    }
};