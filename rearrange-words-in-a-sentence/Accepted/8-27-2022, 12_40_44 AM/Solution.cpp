// https://leetcode.com/problems/rearrange-words-in-a-sentence

class Solution {
public:
    string arrangeWords(string text) {
        stringstream ss(text);
        string word;
        map<int, vector<string>> mp;
        while(ss >> word){
            if(word[0] < 92){
                word[0] += 32;
            }
            mp[word.length()].push_back(word);
        }
        
        string ans = "";
        
        for(auto it: mp){
            vector<string> v = it.second;
            for(string s: v){
                ans += s + " ";
            }
        }
        
        ans.pop_back();
        if(ans[0] > 96){
            ans[0] -= 32;
        }
        return ans;
        
    }
};