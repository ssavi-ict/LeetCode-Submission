// https://leetcode.com/problems/rearrange-words-in-a-sentence

class Solution {
public:
    string arrangeWords(string text) {
        map<int, vector<string> >wordslist;
        
        stringstream ss(text);
        string word;
        while(ss >> word){
            int sz = word.size();
            if(word[0] >='A' && word[0]<='Z') word[0] += 32;
            wordslist[sz].push_back(word);
        }
        
        string ret = "";
        for(auto it: wordslist){
            vector<string>v = it.second;
            for(auto s: v){
                ret = ret + s + " ";
            }
        }
        ret.pop_back();
        ret[0] -= 32;
        return ret;
    }
};