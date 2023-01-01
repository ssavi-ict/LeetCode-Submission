// https://leetcode.com/problems/counting-words-with-a-given-prefix

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(int i=0; i<size(words); i++){
            int j = 0;
            for(; j<size(pref); j++){
                if(words[i][j]!=pref[j]){
                    break;
                }
            }
            if(j==size(pref)) count++;
        }
        return count;
    }
};