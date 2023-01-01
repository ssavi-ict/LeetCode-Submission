// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if( rows == 0) return 0;
        int cols = grid[0].size();
        int nums_island = 0 ;
        int x[4] = {1,0,-1,0};
        int y[4] = {0,-1,0,1};
        for( int i = 0 ; i < rows ; i++)
        {
            for( int j = 0 ; j < cols ; j++)
            {
                if( grid[i][j] == '1')
                {
                    nums_island++;
                    queue<pair<int,int> > qu;
                    qu.push({i,j});
                    while(!qu.empty())
                    {
                        pair ij = qu.front();
                        qu.pop();
                        int r = ij.first , c = ij.second;
                        grid[r][c] = '0';
                        for( int k = 0 ; k < 4 ; k++)
                        {
                            int p = r + x[k] , q = c+y[k];
                            if(p>=0 && p<rows && q>=0 && q<cols && grid[p][q]=='1')
                                qu.push({p,q});
                        }
                    }
                }
            }
        }
        return nums_island;
    }
};