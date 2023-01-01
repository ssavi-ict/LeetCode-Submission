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
            int t_words = words.size();
            ch_cnt.clear();
            
            while(right+word_sz <= str_sz){
                // cout<<left<<' '<<right<<' '<<i<<endl;
                
                string tmp = s.substr(right, word_sz);
                bool excess = false;
                // cout<<tmp<<' '<<freq[tmp]<<endl;
                if(freq.find(tmp)!=freq.end() && freq[tmp] > ch_cnt[tmp]){
                    // cout<<left<<' '<<right<<endl;
                    ch_cnt[tmp]++;
                    t_words--;
                }
                else{
                    excess = true;
                }
                // cout<<"ER "<<excess<<' '<<t_words<<endl;
                right += word_sz;
                if(t_words == 0){
                    ans.push_back(left);
                    ch_cnt[s.substr(left, word_sz)]--;
                    left = left + word_sz;
                    t_words++;
                }
                else if(excess){
                    if(freq.find(tmp)!=freq.end() && freq[tmp]==ch_cnt[tmp]){
                        right = right - word_sz;
                    }
                    ch_cnt.clear();
                    left = right;
                    t_words = words.size();
                }
            }
        }
        return ans;
    }
};