// https://leetcode.com/problems/rearrange-words-in-a-sentence

class Solution {
public:
    string arrangeWords(string text) {
        map<int, vector<string> >wordslist;
        
        stringstream ss(text);
        string word;
        while(ss >> word){
            if(word[0] >='A' && word[0]<='Z') word[0] += 32;
            wordslist[word.length()].push_back(word);
        }
        
        string ret = "";
        for(auto it: wordslist){
            vector<string>v = it.second;
            for(auto s: v){
                ret = ret + s + " ";
            }
        }
        ret.pop_back();
        if(ret[0] > 96)  ret[0] -= 32;
        return ret;
    }
};