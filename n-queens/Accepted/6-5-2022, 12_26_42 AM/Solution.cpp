// https://leetcode.com/problems/n-queens

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
    
    void solve(int col, vector<string> & ans, int q, int n, vector<vector<string>> &fin){
        if(q == 0){
            fin.push_back(ans);
            return;
        }
        if(col> n) return;
        // cout<<"Hi"<<endl;
        for(int i=0; i<n; i++){
            if(valid(i, col, n, ans)){
                // cout<<i<<' '<<col<<' '<<q<<endl;
                ans[i][col] = 'Q';
                solve(col + 1, ans, q-1, n, fin);
                ans[i][col] = '.';
                // solve(col+1, ans, q, n);
            }
            
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>ans;
        vector<vector<string>> fin;
        for(int i=0; i<n; i++){
            string tmp = "";
            for(int j=0; j<n; j++){
                tmp = tmp + ".";
            }
            ans.push_back(tmp);
        }
        
        solve(0, ans, n, n, fin);
        
        return fin;
    }
};