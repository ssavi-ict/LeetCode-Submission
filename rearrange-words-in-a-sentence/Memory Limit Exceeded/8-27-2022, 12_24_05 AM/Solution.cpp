// https://leetcode.com/problems/rearrange-words-in-a-sentence

class Solution {
public:
    string arrangeWords(string text) {
        map<int, vector<string> >wordslist;
        
        stringstream ss(text);
        string word;
        while(ss >> word){
            int sz = word.size();
            wordslist[sz].push_back(word);
        }
        
        string ret = "";
        bool flag = false;
        for(auto it=wordslist.begin(); it!=wordslist.end(); ++it){
            for(int i=0; i<it->second.size(); i++){
                if(flag) ret += " ";
                char ch = it->second[i][0];
                if(ch >='A' && ch<='Z') it->second[i][0] += 32;
                flag = true;
                ret = ret + it->second[i];
            }
        }
        ret[0] -= 32;
        return ret;
    }
};