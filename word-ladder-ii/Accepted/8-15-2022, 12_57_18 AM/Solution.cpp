// https://leetcode.com/problems/word-ladder-ii

class Solution {
public:
    
    /*
    Step 1: A BFS to connect the nodes or to calculate the level.
    Step 2: A DFS to populate the result from the destination node. Going downward according to level.
    */
    
    
    unordered_map<string, int>level;
    vector< vector<string> >ans;
    vector<string>temp;
    
    void dfs(string src, string dest, int word_sz){
        temp.push_back(dest);                       // cog , dog-log, dot
        if(src == dest){
            vector<string>copyoft = temp;
            reverse(copyoft.begin(), copyoft.end());
            ans.push_back(copyoft);
            temp.pop_back();
            return;
        }
        
        int level_cur = level[dest];                                              // 4 | 3-3 | 2 | 2
        for(int i=0; i<word_sz; i++){
            char x = dest[i];
            for(char j='a'; j<='z'; j++){
                dest[i] = j;
                if(level.find(dest)!=level.end() && level[dest] == level_cur-1){  // dog = 3, log = 3 | dot = 2
                    dfs(src, dest, word_sz);                                       // dog, log | dot | lot
                }
            }
            dest[i] = x;
        }
        
        temp.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n_words = wordList.size();
        int word_sz = beginWord.size();
        
        unordered_map<string, bool>stored;
        for(int i=0; i<n_words; i++){
            stored[wordList[i]] = true;
        }
        
        if(!stored[endWord]) return ans;
                                                        // ["hot","dot","dog","lot","log","cog"]
        
        queue<string>myQ;                               // hit
        myQ.push(beginWord);
        level[beginWord] = 0;
        while(!myQ.empty()){
            int q_size = myQ.size();
            while(q_size--){
                string top = myQ.front();               // hit, hot, dot
                int top_level = level[top];             // top_level = 0, top_level = 1, top_level = 2, top_level = 3, top_level = 4
                myQ.pop()
                    ;
                for(int i=0; i<word_sz; i++){
                    char x = top[i];                    // h, i, t | h, o, t | d, o, t | l, o, t | d, o, g | l, o, g | c, o, g
                    for(char j='a'; j<='z'; j++){
                        top[i] = j;                     
                        if(stored.find(top) != stored.end() && level.find(top) == level.end()){
                            level[top] = top_level + 1;     // hot = 1, dot = 2, lot = 2, dog = 3, log = 3
                            myQ.push(top);                  // hot | dot, lot | dog, log | cog
                        }
                    }
                    top[i] = x;
                }
            }
        }
        
        dfs(beginWord, endWord, word_sz); // dfs(hit, cog, 3);
        
        return ans;
    }
};