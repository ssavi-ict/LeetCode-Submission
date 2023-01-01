// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        int match[len1+1][len2+1];
        memset(match, 0, sizeof(match));
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(word1[i-1] == word2[j-1]){
                    match[i][j] = match[i-1][j-1] + 1;
                }
                else{
                    match[i][j] = max(match[i-1][j], match[i][j-1]);
                }
            }
        }
        int lcs = match[len1][len2];
        // cout<<lcs<<endl;
        return (len1 + len2 - (2 * lcs));
    }
};

/*

sea
|
eat

match[1][1] = 0;
match[1][2] = 0;
match[1][3] = 0;

match[2][1] = match[1][0] + 1 = 1;
match[2][2] = max(match[1][2], match[2][1]) = 1
match[2][3] = max(match[1][3], match[2][2]) = 1 

match[3][1] = max(match[2][1], match[3][0]) = 1
match[3][2] = match[2][1] + 1 = 2
match[3][3] = max(match[2][3], match[3][2]) = 1, 2 = 2



*/