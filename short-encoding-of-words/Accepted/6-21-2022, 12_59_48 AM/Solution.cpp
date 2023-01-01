// https://leetcode.com/problems/short-encoding-of-words

class Solution {
public:
    
    struct TrieNode{
        struct TrieNode * next[26];
    };
    
    struct TrieNode * getNode(){
        struct TrieNode * pNode = new TrieNode;
        for(int i=0; i<26; i++){
            pNode->next[i] = NULL;
        }
        return pNode;
    }
    
    struct TrieNode * root = getNode();
    int count = 0;
    
    void solve(struct TrieNode * root, int cnt){
        bool ektao = false;
        for(int i=0; i<26; i++){
            if(root->next[i]){
                ektao = true;
                solve(root->next[i], cnt+1);
            }
        }
        if(!ektao){
            count += cnt + 1;
        }
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            struct TrieNode * curr = root;
            for(int j=words[i].size()-1; j>=0; j--){
                int idx = words[i][j] - 'a';
                if(curr->next[idx]==NULL){
                    curr->next[idx] = getNode();
                }
                curr = curr->next[idx];
            }
        }
        solve(root, 0);
        return count;
    }
};