// https://leetcode.com/problems/find-players-with-zero-or-one-losses

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int player_status[100005];
        memset(player_status, -1, sizeof(player_status));
        int n = matches.size();
        int to_m = 0;
        for(int i=0; i<n; i++){
            if(player_status[matches[i][0]] == -1) {
                player_status[matches[i][0]]++;
            }
            if(player_status[matches[i][1]] == -1) {
                player_status[matches[i][1]]++;
            }
            player_status[matches[i][1]]++;
            to_m = max(to_m, max(matches[i][0], matches[i][1]));
        }

        vector<vector<int>>ans(2);
        for(int i=1; i<=to_m; i++){
            if(player_status[i] == -1) continue;
            if(player_status[i] == 0){
                ans[0].push_back(i);
            }
            else if(player_status[i] == 1){
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};