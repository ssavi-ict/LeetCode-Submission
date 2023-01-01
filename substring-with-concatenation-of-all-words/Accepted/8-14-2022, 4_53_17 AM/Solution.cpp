// https://leetcode.com/problems/substring-with-concatenation-of-all-words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int>freq, ch_cnt;
        for(int i=0; i<words.size(); i++){
            freq[words[i]]++;
        }
        
        int str_sz = s.size(), word_sz = words[0].size();
        vector<int>ans;
        for(int i=0; i<word_sz; i++){
            int left = i, right = i;
            int t_words = 0;
            ch_cnt.clear();
            
            while(right+word_sz <= str_sz){
                string tmp = s.substr(right, word_sz);
                if(freq.find(tmp)!=freq.end()){
                    if(freq[tmp] > ch_cnt[tmp]){
                        ch_cnt[tmp]++; 
                        t_words++;
                        right = right + word_sz;
                    }
                    else{
                        t_words--;
                        ch_cnt[s.substr(left, word_sz)]--;
                        left = left + word_sz;
                    }
                }
                else{
                    ch_cnt.clear();
                    left = right = right + word_sz;
                    t_words = 0;
                }
                if(t_words==words.size()){
                    ans.push_back(left);
                    ch_cnt[s.substr(left, word_sz)]--;
                    t_words--;
                    left = left + word_sz;
                }
            }
        }
        return ans;
    }
};