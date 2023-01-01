// https://leetcode.com/problems/word-ladder

class Solution {
public:
    unordered_map<string, bool>stored;
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n_words = wordList.size();
        int word_sz = beginWord.size();
        for(int i=0; i<n_words; i++){
            stored[wordList[i]] = true;
        }
        
        if(stored.find(endWord)==stored.end()) return 0;
        
        queue<string>myQ;
        unordered_map<string, int>level;
        
        myQ.push(beginWord);
        int ans = 0;
        level[beginWord] = 1;
        while(!myQ.empty()){
            int q_size = myQ.size();
            while(q_size--){
                auto top = myQ.front();
                myQ.pop();
                int current_lvl = level[top];
                
                for(int i=0; i<word_sz; i++){
                    char x = top[i];
                    for(char j='a'; j<='z'; j++){
                        top[i] = j;
                        if(stored.find(top)!=stored.end() && level.find(top)==level.end()){
                            level[top] = current_lvl + 1;
                            myQ.push(top);
                            ans = max(ans, current_lvl+1);
                            if(top == endWord) return ans;
                        }
                    }
                    top[i] = x;
                }
            }
        }
        return 0;
    }
};