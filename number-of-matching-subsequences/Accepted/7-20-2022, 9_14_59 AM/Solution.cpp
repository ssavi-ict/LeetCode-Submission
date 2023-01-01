// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector< vector<int> >idx_chars(26);
        for(int i=0; i<size(s); i++){
            idx_chars[s[i]-'a'].push_back(i);
        }
        
        int count = 0;
        for(int i=0; i<size(words); i++){
            int cur = -1; bool flag = true;
            for(int j=0; j<size(words[i]); j++){
                int idx = words[i][j] - 'a';
                // cout<<words[i][j]<<' '<<idx<<endl;
                int found = upper_bound(idx_chars[idx].begin(), idx_chars[idx].end(), cur) - idx_chars[idx].begin();
                // cout<<cur<<' '<<found<<endl;
                if(found>=size(idx_chars[idx]) || idx_chars[idx][found]<=cur){
                    flag = false;
                    break;
                }
                cur = idx_chars[idx][found];
            }
            if(flag){
                // cout<<i<<" Hi"<<endl;
                count++;
            }
        }
        return count;
    }
};