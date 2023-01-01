// https://leetcode.com/problems/number-of-islands-ii

class Solution {
public:
    const int fx[4] = {+1, -1, +0, +0};
    const int fy[4] = {+0, +0, +1, -1};
    
    void init(int numOfNodes, vector<int> &par)
    {
        for(int i=1 ; i<=numOfNodes ; i++)
            par[i] = i;
    }
    
    int findPar(int u, vector<int> &par)
    {
        if(par[u] == u)
            return u;
        return par[u] = findPar(par[u], par);
    }
    
    void makeSet(int u, int v, vector<int> &par)
    {
        u = findPar(u, par);
        v = findPar(v, par);
        if(u != v){
            par[u] = v;
        }
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int numOfNodes = m*n, cnt = 0;
        vector<int> par(numOfNodes+5, 0), isLand(numOfNodes+5, 0), ans;
        
        init(numOfNodes, par);
        
        for(auto pos : positions) {
            int u = (pos[0]*n) + (pos[1]+1);
            set<int> prevLands;
            
            if(isLand[u]){
                ans.push_back(cnt);
                continue;
            }
            
            for(int k=0 ; k<4 ; k++) {
                int nx = pos[0] + fx[k];
                int ny = pos[1] + fy[k];
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                
                int v = (nx*n)+(ny+1);
                
                if(isLand[v])
                    prevLands.insert(findPar(v, par));
            }

            isLand[u] = 1;
            for(int k=0 ; k<4 ; k++) {
                int nx = pos[0] + fx[k];
                int ny = pos[1] + fy[k];
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                
                int v = (nx*n)+(ny+1);
                
                if(isLand[v])
                    makeSet(u, v, par);
            }

            if(prevLands.empty()) {
                cnt++;
            }
            else {
                cnt += (1-prevLands.size());
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};