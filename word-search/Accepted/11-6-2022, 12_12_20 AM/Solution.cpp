// https://leetcode.com/problems/word-search

class Solution {
public:
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    bool isFound(int src_x, int src_y, int m, int n, vector<vector<char>>& board, int match_index, string & word){
        if(match_index >= word.size()) return true;
        if(board[src_x][src_y] == '#') return false;
        char ch = board[src_x][src_y];
        // cout<<match_index<<' '<<board[src_x][src_y]<<endl;
        
        board[src_x][src_y] = '#';
        bool ret = false;
        for(int i=0; i<4; i++){
            int new_x = src_x + dx[i];
            int new_y = src_y + dy[i];
            if(new_x<0 || new_x>=m || new_y<0 || new_y>=n || board[new_x][new_y] != word[match_index]) continue;
            ret = ret | isFound(new_x, new_y, m, n, board, match_index+1, word);
        }
        board[src_x][src_y] = ch;
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    if(isFound(i, j, m, n, board, 1, word)) return true;
                }
            }
        }
        return false;
    }
};