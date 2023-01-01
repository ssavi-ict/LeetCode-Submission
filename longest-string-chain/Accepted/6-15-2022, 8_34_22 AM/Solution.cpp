// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    
    struct comp{
        bool operator()(const string &a, const string &b){
            return a.size() < b.size();
        }
    };
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp());
        unordered_map<string, int>chain;
        int ans = 0;
        for (int i=0; i<words.size(); i++){
            int len = words[i].size();
            if(len == 1){
                chain[words[i]] = 1;
                ans = 1;
                continue;
            }
            for(int j=0; j<len; j++){
                if(j==0){
                    // cout<<"H "<<words[i].substr(1, len-1)<<endl;
                    chain[words[i]] = max(chain[words[i]], chain[words[i].substr(1, len-1)]+1);
                }
                else if(j == len-1){
                    // cout<<"K "<<words[i].substr(0, len-1)<<endl;
                    chain[words[i]] = max(chain[words[i]], chain[words[i].substr(0, len-1)]+1);
                }
                else{
                    // cout<<"P "<<words[i].substr(0, j)+words[i].substr(j+1)<<endl;
                    chain[words[i]] = max(chain[words[i]], chain[words[i].substr(0, j)+words[i].substr(j+1)]+1);
                }
                ans = max(ans, chain[words[i]]);
            }
        }
        return ans;
    }
};