// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        int n = s.size();
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int count = 0;
        for(int i=1; i<26; i++){
            if(freq[i] == 0) break;
            if(freq[i] >= freq[i-1]){
                int extra = (freq[i-1] - 1)>0? freq[i-1] - 1 : 0;
                count += (freq[i] - extra);
                freq[i] = extra;
            }
            // cout<<count<<' '<<freq[i]<<endl;
        }
        return count;
    }
};