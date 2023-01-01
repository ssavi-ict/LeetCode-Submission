// https://leetcode.com/problems/rearrange-words-in-a-sentence

class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<int, pair<int, string>> >storage;
        
        stringstream ss(text);
        string word;
        int i = 0;
        while(ss >> word){
            int sz = word.size();
            storage.push_back(make_pair(sz, make_pair(i++, word)));
        }
        
        stable_sort(storage.begin(), storage.end());
        
        string ret = "";
        bool flag = false;
        for(int j = 0; j<storage.size(); j++){
            if(flag) ret += " ";
            char ch = storage[j].second.second[0];
            if(ch >='A' && ch<='Z') storage[j].second.second[0] += 32;
            flag = true;
            ret = ret + storage[j].second.second;
        }
        ret[0] -= 32;
        return ret;
    }
};