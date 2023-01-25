class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        if(board[0][0] != -1 || board[n-1][0]!=-1) return -1;
        
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
        vector<int>distance(n*n + 1, -1);
        distance[1] = 0;

        while(!coord.empty()){
            int top = coord.front();
            coord.pop();
            for(int i=top+1; i<=min(top+6, n*n); i++){
                int next = i;
                int x = cell[next][0], y = cell[next][1];
                if(board[x][y] != -1){
                    next = board[x][y];
                }
                if(distance[next] == -1){
                    coord.push(next);
                    distance[next] = distance[top] + 1;
                }
                if(next == n*n) return distance[next];
            }
        }
        return -1;
    }
};