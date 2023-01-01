// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        int m = triangle.size();
        
        for(int i=0; i<m; i++){
            int n = triangle[i].size();
            for(int j=0; j<n; j++){
                if(i==0){
                    break;
                }
                if(j==0){
                    triangle[i][j] += triangle[i-1][j];
                }
                else if(j==n-1){
                    triangle[i][j] += triangle[i-1][j-1];
                }
                else{
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
            }
        }
        for(int i=0; i<triangle[m-1].size(); i++){
            ans = min(ans, triangle[m-1][i]);
        }
        return ans;
    }
};