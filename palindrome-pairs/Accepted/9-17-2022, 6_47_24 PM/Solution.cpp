// https://leetcode.com/problems/palindrome-pairs

class Solution {
public:
    
    struct TrieNode{
        int index;
        struct TrieNode * next[26];
    };
    
    struct TrieNode * getNode(){
        struct TrieNode * newNode = new TrieNode;
        newNode->index = -1;
        for(int i=0; i<26; i++){
            newNode->next[i] = NULL;
        }
        return newNode;
    }
    
    void insert(string & s, TrieNode * root, int idx){
        int sz = s.size();
        struct TrieNode * curr = root;
        
        for(int i=sz-1; i>=0; i--){
            int u = s[i] - 'a';
            if(curr->next[u] == NULL){
                curr->next[u] = getNode();
            }
            curr = curr->next[u];
        }
        curr->index = idx;
        return;
    }
    
    bool is_pallindrome(string & str, int left, int right){
        while(left<=right){
            if(str[left]!=str[right]) return false;
            left++, right--;
        }
        return true;
    }
    
    void find_other_pallindrome(TrieNode * root, vector<int> & list_of_pal, string s = ""){
        
        if(root->index!=-1){
            if(is_pallindrome(s, 0, s.size() - 1)){
                list_of_pal.push_back(root->index);
            }
        }
        
        for(int i=0; i<26; i++){
            if(root->next[i]!=NULL){
                char newChar = i + 'a';
                s.push_back(newChar);
                find_other_pallindrome(root->next[i], list_of_pal, s);
                s.pop_back();
            }
        }
    }
    
    vector<int>search(TrieNode * root, string & s){
        vector<int>list_of_pal;
        int sz = s.size();
        struct TrieNode * cur = root;
        
        for(int i=0; i<sz; i++){
            int idx = s[i] - 'a';
            if(cur->index!=-1){
                if(is_pallindrome(s, i, sz-1)){
                    list_of_pal.push_back(cur->index);
                }
            }
            if(cur->next[idx]==NULL){
                return list_of_pal;
            }
            cur = cur->next[idx];
        }
        find_other_pallindrome(cur, list_of_pal);
        return list_of_pal;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        struct TrieNode * root = getNode(); 
        int n = words.size();
        for(int i=0; i<n; i++) insert(words[i], root, i);
        
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            vector<int>pal_list = search(root, words[i]);
            for(int j=0; j<pal_list.size(); j++){
                if(pal_list[j] != i){
                    ans.push_back({i, pal_list[j]});
                }
            }
        }
        return ans;
    }
};

/*

"baa", "aabbb", "aabbaa", "baa"
a->a->b(end)->b->a->a(end)
b->b->b->a->a


*/


























