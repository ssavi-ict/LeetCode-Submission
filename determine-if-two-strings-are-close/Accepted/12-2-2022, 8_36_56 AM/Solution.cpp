// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1 != n2) return false;
        vector<int>freq_w1(26, 0), freq_w2(26, 0);
        for(int i=0; i<n1; i++) freq_w1[word1[i] - 'a']++;
        for(int i=0; i<n2; i++){
            if(freq_w1[word2[i] - 'a'] == 0) return false;
            freq_w2[word2[i] - 'a']++;
        }
        sort(freq_w1.begin(), freq_w1.end());
        sort(freq_w2.begin(), freq_w2.end());
        for(int i=0; i<26; i++){
            if(freq_w1[i] != freq_w2[i]) return false;
        }
        return true;
    }
};