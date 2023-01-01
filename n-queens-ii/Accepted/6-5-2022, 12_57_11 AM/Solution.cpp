// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    
    int dx4[4] = {-1, -1, 1, 1};
    int dy4[4] = {1, -1, 1, -1};
    
    
    bool valid(int r, int c, int n, vector<string>&ans){
        for(int i=0; i<n; i++){
            if(ans[r][i] == 'Q') return false;
        }
        //for(int i=0; i<n; i++){
            //if(ans[i][c] == 'Q') return false;
        //}
        int rr = r, cc = c;
        int count = 2*n, mul = 0;
        while(count--){
            for(int k=0; k<4; k++){
                int i = rr + dx4[k]*mul;
                int j = cc + dy4[k]*mul;
                if((i>=0 && i<n && j>=0 && j<n)){
                    if(ans[i][j] == 'Q') return false;
                }
            }
            mul++;
        }
        
        return true;
    }
    
    int solve(int col, vector<string> & ans, int q, int n){
        if(q == 0){
            return 1;
        }
        if(col> n) return 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(valid(i, col, n, ans)){
                // cout<<i<<' '<<col<<' '<<q<<endl;
                ans[i][col] = 'Q';
                cnt += solve(col + 1, ans, q-1, n);
                ans[i][col] = '.';
            }
        }
        return cnt;
    }
    
    int totalNQueens(int n) {
        vector<string>ans;
        for(int i=0; i<n; i++){
            string tmp = "";
            for(int j=0; j<n; j++){
                tmp = tmp + ".";
            }
            ans.push_back(tmp);
        }
        return solve(0, ans, n, n);
    }
};