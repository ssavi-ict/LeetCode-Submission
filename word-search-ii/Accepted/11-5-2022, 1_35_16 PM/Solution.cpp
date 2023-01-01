// https://leetcode.com/problems/word-search-ii

class Solution {
public:
    
    struct TrieNode{
        struct TrieNode * child[26];
        string word;
    };
    
    struct TrieNode * getNode(){
        struct TrieNode * newNode = new TrieNode;
        newNode->word = "";
        for(int i=0; i<26; i++){
            newNode->child[i] = NULL;
        }
        return newNode;
    }
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    void insertWord(struct TrieNode * root, string & word){
        int word_size = word.size();
        struct TrieNode * currentNode = root;
        for(int i=0; i<word_size; i++){
            int index = word[i] - 'a';
            if(currentNode->child[index] == NULL){
                currentNode->child[index] = getNode();
            }
            currentNode = currentNode->child[index];
        }
        currentNode->word = word;
    }
    
    void wordFinder(int x, int y, int m, int n, vector<vector<char>>& board, struct TrieNode * currentNode, vector<string> & retWords){
        char current_ch = board[x][y];
        if(current_ch == '#')  return;
        int index = current_ch - 'a';
        currentNode = currentNode->child[index];
        if(currentNode == NULL) return;
        
        if(currentNode->word.size() > 0){
            retWords.push_back(currentNode->word);
            currentNode->word = "";
        }
        
        board[x][y] = '#';
        for(int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x<0 || new_x>=m || new_y<0 || new_y>=n) continue;
            wordFinder(new_x, new_y, m, n, board, currentNode, retWords);
        }
        board[x][y] = current_ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode * root = getNode();
        int word_size = words.size();
        for(auto word: words){
            insertWord(root, word);
        }
        
        vector<string>retWords;
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                wordFinder(i, j, m, n, board, root, retWords);
            }
        }
        return retWords;
    }
};






















