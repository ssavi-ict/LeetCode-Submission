// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<int>freq(80, 0);
        for(int i=0; i<n; i++){
            freq[s[i]-'0']++;
        }
        priority_queue<pair<int, char>>top_char;
        for(char i='0'; i<='z'; i++){
            if(freq[i-'0'] == 0) continue;
            top_char.push(make_pair(freq[i-'0'], i));
        }

        s = "";
        while(!top_char.empty()){
            auto current = top_char.top();
            top_char.pop();
            for(int i=0; i<current.first; i++){
                s += current.second;
            }
        }
        return s;
    }
};