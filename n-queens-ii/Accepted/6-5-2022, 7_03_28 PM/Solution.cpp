// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    
    int dx[4] = {-1, -1, 1};
    int dy[4] = {1, -1, -1};
    
    bool valid(int r, int c, vector<int>&state, int n){
        for(int i=0; i<n; i++){
            if(state[r] & (1<<i)) return false;
        }
        
        int count = 2*n;
        int mul = 0;
        while(count--){
            for(int i=0; i<4; i++){
                int rr = r + dx[i]*mul;
                int cc = c + dy[i]*mul;
                if(rr>=0 && rr<n && cc>=0 && cc<n){
                    if(state[rr] & (1<<cc)) return false;
                }
            }
            mul++;
        }
        return true;
    }
    
    int solve(int col, vector<int>&state, int q, int n){
        if(q<=0){
            return 1;
        }
        if(col>=n) return 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(valid(i, col, state, n)){
                // cout<<i<<' '<<col<<' '<<q<<endl;
                state[i] = state[i] | (1 << col);
                cnt = cnt + solve(col + 1, state, q-1, n);
                state[i] = state[i] & (0 << col);
            }
        }
        return cnt;
    }
    
    int totalNQueens(int n) {
        vector<int>state(n, 0);
        return solve(0, state, n, n);
    }
};