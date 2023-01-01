// https://leetcode.com/problems/search-suggestions-system

class Solution {
public:
    
    struct TrieNode{
       struct TrieNode * next[26];
        bool isEnd;
    };
    
    struct TrieNode * getNode(){
        struct TrieNode * current = new TrieNode;
        for(int i=0; i<26; i++){
            current->next[i] = NULL;
        }
        current->isEnd = false;
        return current;
    }
    
    struct TrieNode * root = getNode();
    
    void insert(vector<string>&products){
        for(int i=0; i<products.size(); i++){
            struct TrieNode * current = root;
            for(int j=0; j<products[i].size(); j++){
                int idx = products[i][j] - 'a';
                if(current->next[idx] == NULL){
                    current->next[idx] = getNode();
                }
                current = current->next[idx];
            }
            current->isEnd = true;
        }
    }
    
    void search(struct TrieNode * root, vector<string>&result, string &str){
        if(result.size()==3){
            return;
        }
        // cout<<str<<endl;
        if(root->isEnd){
            result.push_back(str);
        }
        for(char i='a'; i<='z'; i++){
            int idx = i-'a';
            if(root->next[idx]){
                str.push_back(i);
                search(root->next[idx], result, str);
                str.pop_back();
            }
        }
    }
    
    vector< vector<string> >ans;
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        insert(products);
        bool OK = false;
        for(int i=0; i<searchWord.size(); i++){
            TrieNode * current = root;
            vector<string>ret;
            if(OK){
                ans.push_back(ret);
                continue;
            }
            for(int j=0; j<=i; j++){
                int idx = searchWord[j] - 'a';
                if(current->next[idx] == NULL){
                    ans.push_back(ret);
                    OK = true;
                    break;
                }
                current = current->next[idx];
            }
            
            if(OK) continue;
            
            string str = searchWord.substr(0,i+1);
            search(current, ret, str);
            ans.push_back(ret);
        }
        return ans;
    }
};