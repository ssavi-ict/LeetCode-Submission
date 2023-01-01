// https://leetcode.com/problems/print-words-vertically

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        words.emplace_back();
        
        int mxWordSize = 0;
        for(char c: s) {
            if(c == ' ')
                words.emplace_back();
            else {
                words.back().push_back(c);
                mxWordSize = max(mxWordSize, (int)words.back().size());
            }
        }
        
        vector<string> result(mxWordSize);
        for(string word: words) {
            for(int i = 0; i < mxWordSize; i++) {
                result[i].push_back(i < word.size() ? word[i] : ' ');
            }
        }
        
        for(string& word: result) {
            while(word.back() == ' ')
                word.pop_back();
        }
        return result;  
    }
};