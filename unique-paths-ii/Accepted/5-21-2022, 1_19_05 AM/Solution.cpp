// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        int dp[2][n+1];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0){
                    if(!j) continue;
                    dp[i][j] = dp[i][j-1];
                    if(obstacleGrid[i][j]){
                        dp[i][j] = 0;
                    }
                }
                else{
                    if(obstacleGrid[i][j]){
                        dp[i%2][j] = 0;
                        continue;
                    }
                    if(i%2){
                        dp[i%2][j] = (j==0)? dp[i%2 - 1][j] : dp[i%2 - 1][j] + dp[i%2][j-1];
                    }
                    else{
                        dp[i%2][j] = (j==0)? dp[1 - i%2][j] : dp[1 - i%2][j] + dp[i%2][j-1];
                    }
                }
            }
        }
        return (m%2)?dp[0][n-1]:dp[1][n-1];
    }
};