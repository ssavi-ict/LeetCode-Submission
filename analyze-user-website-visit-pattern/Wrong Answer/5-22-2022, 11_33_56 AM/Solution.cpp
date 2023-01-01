// https://leetcode.com/problems/analyze-user-website-visit-pattern

class Solution {
    // Time: 12.14
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, map<int, string>>mp;
        int n = username.size();
        vector<string>output;
        map<string, int>cnt;
        int mxCnt = 0;
        string mxMatch = "";
        
        for(int i = 0; i < n; i++){
            mp[username[i]][timestamp[i]] = website[i];
        }
        
        for(auto user : mp){
            auto lst = user.second;
            vector<string>websiteLst;
            
            for(auto site: lst){
                websiteLst.push_back(site.second);
            }
            
            for(int i = 0; i < websiteLst.size() - 2; i++){
                for(int j = i + 1; j < websiteLst.size() - 1; j++){
                    for(int k = j + 1; k < websiteLst.size(); k++){
                        string str = websiteLst[i] + " " + websiteLst[j] + " " + websiteLst[k];
                        cnt[str]++;
                        if(cnt[str] > mxCnt){
                            mxMatch = str;
                        }
                    }
                }
            }
        }
        
        for(auto item: cnt){
            if(item.second == mxCnt){
                mxMatch = item.first;
                break;
            }
        }
        
        string cur = "";
        int pos = 0;
        while(pos < mxMatch.size()){
            if(mxMatch[pos] == ' '){
                output.push_back(cur);
                cur = "";
            }
            else cur += mxMatch[pos];
            pos++;
        }
        if(cur != "") output.push_back(cur);
        
        return output;
    }
};