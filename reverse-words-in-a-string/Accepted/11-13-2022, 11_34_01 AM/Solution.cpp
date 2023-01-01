// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        stringstream seperator(s);
        vector<string>wordVector;
        while(seperator >> s){
            wordVector.push_back(s);
        }
        s = "";
        int word_size = wordVector.size();
        for(int i=word_size-1; i>=0; i--){
            if(i < word_size - 1) s += " ";
            s += wordVector[i];
        }
        return s;
    }
};