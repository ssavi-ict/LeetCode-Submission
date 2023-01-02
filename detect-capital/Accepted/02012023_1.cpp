class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap_count = 0;
        int n = word.size();
        for(int i=0; i<n; i++){
            if(word[i] >= 'A' && word[i] <= 'Z') cap_count++;
        }
        if(cap_count == n || cap_count == 0) return true;
        if(cap_count == 1 && (word[0]>='A' && word[0]<='Z')) return true;
        return false;
    }
};