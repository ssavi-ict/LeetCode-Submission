// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int table[501][501];
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        for(int i=1; i<=sz1; i++){
            for(int j=1; j<=sz2; j++){
                if(word1[i-1] == word2[j-1]){
                    table[i][j] = table[i-1][j-1] + 1;
                }
                else{
                    table[i][j] = max(table[i][j-1], table[i-1][j]);
                }
            }
        }
        return (sz1 + sz2 - 2*(table[sz1][sz2]));
    }
};