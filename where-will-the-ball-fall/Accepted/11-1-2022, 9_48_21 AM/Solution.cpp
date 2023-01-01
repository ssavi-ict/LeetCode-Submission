// https://leetcode.com/problems/where-will-the-ball-fall

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>answer(n, -1);
        for(int j=0; j<n; j++){
            int current = j;
            for(int i=0; i<m; i++){
                int next = current + grid[i][current];
                if(next < 0 || next >= n || grid[i][current] != grid[i][next]){
                    answer[j] = -1; break; 
                }
                answer[j] = next;
                current = next;
            }
        }
        return answer;
    }
};