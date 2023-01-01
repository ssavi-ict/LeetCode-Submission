// https://leetcode.com/problems/alien-dictionary

class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<int>>graph(26);
        unordered_set<int>chars;
        int inTime[26];
        memset(inTime, 0, sizeof inTime);
        int n = words.size();
        string output = "";
        queue<int>st;
        
        for(auto str: words){
            for(auto c: str){
                chars.insert(c - 'a');
            }
        }
        
        for(int i = 1; i < n; i++){
            string s2 = words[i];
            string s1 = words[i - 1];
            int len1 = s1.size();
            int len2 = s2.size();
            int j = 0;
            
            while(j < len1 && j < len2){
                int a = s1[j] - 'a';
                int b = s2[j] - 'a';
                
                if(a != b){
                    inTime[b]++;
                    graph[a].push_back(b);
                    break;
                }
                j++;
            }
            
            if(j == len2)
                return "";
        }
        
        for(auto c: chars){
            if(inTime[c] == 0){
                st.push(c);
            }
        }
        
        
        while(!st.empty()){
            int now = st.front();
            st.pop();
            output += (now + 'a');
            for(auto v: graph[now]){
                inTime[v]--;
                if(inTime[v] == 0){
                    st.push(v);
                }
            }
        }
        
        for(auto v: chars){
            if(inTime[v] != 0){
                return "";
            }
        }
        
        return output;
    }
};