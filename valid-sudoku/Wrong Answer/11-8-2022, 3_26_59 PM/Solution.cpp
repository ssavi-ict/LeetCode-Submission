// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    
    int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    
    int to_int(char x){
        int number = x - '0';
        return number;
    }
    
    bool is_row_column_valid(vector<vector<char>>& board, int x_start, int y_start){
        // cout<<x_start<<' '<<y_start<<endl;
        int rowWiseVal = 0;
        for(int i=0; i<9 && board[x_start][i]!='.' ; i++){
            int cell_value = to_int(board[x_start][i]);
            if(rowWiseVal & (1 << (cell_value - 1))) return false;
            rowWiseVal = rowWiseVal | (1 << (cell_value - 1));
        }
        
        int colWiseVal = 0;
        for(int i=0; i<9 && board[i][y_start]!='.'; i++){
            int cell_value = to_int(board[i][y_start]);
            // cout<<cell_value<<endl;
            if(colWiseVal & (1 << (cell_value - 1))) return false;
            colWiseVal = colWiseVal | (1 << (cell_value - 1));
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<pair<int, int>>center;
        for(int i=1; i<9; i+=3){
            for(int j=1; j<9; j+=3){
                center.push_back(make_pair(i, j));
            }
        }
        
        for(int i=0; i<center.size(); i++){
            int start_x = center[i].first, start_y = center[i].second;
            int current_box_number= 0;
            int cell_value;
            if(board[start_x][start_y] != '.'){
                cell_value = to_int(board[start_x][start_y]);
                current_box_number = (1 << (cell_value - 1));
            }
            // cout<<cell_value<<' '<<current_box_number<<endl;
            for(int j=0; j<8; j++){
                int cell_x = start_x + dx[j];
                int cell_y = start_y + dy[j];
                if(!is_row_column_valid(board, cell_x, cell_y)) return false;
                
                if(board[cell_x][cell_y] == '.')  continue;
                cell_value = to_int(board[cell_x][cell_y]);
                if(current_box_number & (1 << (cell_value - 1))) return false;
                current_box_number = current_box_number | (1 << (cell_value - 1));
                
            }
        }
        return true;
    }
};