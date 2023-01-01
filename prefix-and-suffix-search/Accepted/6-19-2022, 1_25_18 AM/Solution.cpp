// https://leetcode.com/problems/prefix-and-suffix-search

class WordFilter {
public:
    
    struct TrieNode{
        struct TrieNode * next[27];
        int idx;
    };
    
    struct TrieNode * getNode(){
        struct TrieNode * pNode = new TrieNode;
        pNode->idx = -1;
        for(int i=0; i<27; i++){
            pNode->next[i] = NULL;
        }
        return pNode;
    }
    
    struct TrieNode * root = getNode();
    
    void insert(string &str, int pos){
        for(int j=str.size()-1; j>=0; j--){
            struct TrieNode * current = root;
            for(int i=j; i<str.size(); i++){
                // cout<<str[i];
                int idx = str[i] - 'a';
                if(current->next[idx] == NULL){
                    current->next[idx] = getNode();
                }
                current = current->next[idx];
                current->idx = pos;
            }
            
            int idx = 26;
            if(current->next[idx] == NULL){
                current->next[idx] = getNode();
            }
            current = current->next[idx];
            current->idx = pos;
            // cout<<'$';
            
            for(int i=0; i<str.size(); i++){
                // cout<<str[i];
                int idx = str[i] - 'a';
                if(current->next[idx] == NULL){
                    current->next[idx] = getNode();
                }
                current = current->next[idx];
                current->idx = pos;
            }
            // cout<<endl;
        }
    }
    
    int search(string str){
        struct TrieNode * current = root;
        for(int i=0; i<str.size(); i++){
            // cout<<str[i];
            int idx = (str[i]=='$')?26:str[i]-'a';
            if(current->next[idx]==NULL) return -1;
            current = current->next[idx];
        }
        // cout<<endl;
        return current->idx;
    }

    
    WordFilter(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            insert(words[i], i);
        }
    }
    
    int f(string prefix, string suffix) {
        suffix += '$';
        for(int i=0; i<prefix.size(); i++){
            suffix += prefix[i];
        }
        return search(suffix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */