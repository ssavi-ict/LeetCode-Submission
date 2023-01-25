class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>>cell(n*n+1, vector<int>(2));
        int cellNo = 1, st = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n && !st; j++){
                cell[cellNo++] = {i, j};
            }
            for(int j=n-1; j>=0 && st; j--){
                cell[cellNo++] = {i, j};
            }
            st = st ^ 1;
        }
        queue<int>coord;
        coord.push(1);
        int step = 1;
        vector<bool>used(n*n+1, false);

        while(!coord.empty()){
            int qsize = coord.size();
            while(qsize--){
                int top = coord.front();
                coord.pop();
                for(int i=1; i<=6; i++){
                    int next = top + i;
                    int x = cell[next][0], y = cell[next][1];
                    if(board[x][y] != -1){
                        next = board[x][y];
                    }
                    if(used[next]) continue;
                    if(next == n*n) return step;
                    used[next] = true;
                    coord.push(next);
                }
            }
            step++;
        }
        return -1;
    }
};