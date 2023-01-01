// https://leetcode.com/problems/word-ladder-ii

class Solution {
public:
    
    unordered_map<string, bool>stored;
    unordered_map<string, bool>visited;
    vector< vector<string> >ans;
    int ansLen;
    
    void solve(string src, string dest, vector<string>&candidate){
        
        if(src == dest){
            if(candidate.size() < ansLen){
                ansLen = candidate.size();
                ans.clear();
            }
            if(candidate.size()==ansLen)
                ans.push_back(candidate);
            return;
        }
        
        // if(visited.find(src)!=visited.end() && visited[src]) return;
        
        
        for(int j=0; j<src.size(); j++){
            for(char i='a'; i<='z'; i++){
                string tmp = src;
                tmp[j] = i;
                if(stored[tmp] && !visited[tmp]){
                    visited[tmp] = true;
                    // cout<<src<<' '<<tmp<<endl;
                    candidate.push_back(tmp);
                    solve(tmp, dest, candidate);
                    candidate.pop_back();
                    visited[tmp] = false;
                }
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(int i=0; i<wordList.size(); i++){
            stored[wordList[i]] = true;
        }
        vector<string>candidate;
        candidate.push_back(beginWord);
        ansLen = INT_MAX;
        
        solve(beginWord, endWord, candidate);
        return ans;
    }
};