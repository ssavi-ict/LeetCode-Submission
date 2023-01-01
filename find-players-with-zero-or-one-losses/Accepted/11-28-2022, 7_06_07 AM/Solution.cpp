// https://leetcode.com/problems/find-players-with-zero-or-one-losses

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int player_status[2][100005];
        memset(player_status, 0, sizeof(player_status));
        int n = matches.size();
        int to_m = 0;
        for(int i=0; i<n; i++){
            player_status[0][matches[i][0]]++;
            player_status[1][matches[i][1]]++;
            to_m = max(to_m, max(matches[i][0], matches[i][1]));
        }

        vector<vector<int>>ans(2);
        for(int i=1; i<=to_m; i++){
            if(player_status[0][i] + player_status[1][i] == 0) continue;
            if(player_status[1][i] == 0){
                ans[0].push_back(i);
            }
            else if(player_status[1][i] == 1){
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};