// https://leetcode.com/problems/unique-morse-code-words

class Solution {
public:
    
    string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string>myset;
    
    int uniqueMorseRepresentations(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            string trans = "";
            for(int j=0; j<words[i].size(); j++){
                trans += code[words[i][j] - 'a'];
            }
            myset.insert(trans);
        }
        return myset.size();
    }
};