// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    
    int dx4[4] = {-1, -1, 1, 1};
    int dy4[4] = {1, -1, 1, -1};
    
    
    bool valid(int r, int c, int n, vector<vector<bool>> & state){
        for(int i=0; i<n; i++){
            if(state[r][i]) return false;
        }
        int rr = r, cc = c;
        int count = 2*n, mul = 0;
        while(count--){
            for(int k=0; k<4; k++){
                int i = rr + dx4[k]*mul;
                int j = cc + dy4[k]*mul;
                if((i>=0 && i<n && j>=0 && j<n)){
                    if(state[i][j]) return false;
                }
            }
            mul++;
        }
        
        return true;
    }
    
    int solve(int col, vector<vector<bool>> & state, int q, int n){
        if(q == 0){
            return 1;
        }
        if(col> n) return 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(valid(i, col, n, state)){
                state[i][col] = true;
                cnt += solve(col + 1, state, q-1, n);
                state[i][col] = false;
            }
        }
        return cnt;
    }
    
    int totalNQueens(int n) {
        vector<vector<bool>>state(n, vector<bool>(n, 0));
        return solve(0, state, n, n);
    }
};