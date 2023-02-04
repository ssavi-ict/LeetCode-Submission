class Solution {
public:

    int solve(int pos, int last,  vector<vector<int>> & dp,  vector<pair<int, int>> & teams){
        if(pos >= teams.size()) return 0;
        if(dp[pos][last+1] != -1) return dp[pos][last + 1];
        int maxScore = 0;
        if(last == -1 || teams[pos].second >= teams[last].second){
            dp[pos][last+1] = max(dp[pos][last+1], teams[pos].second + solve(pos+1, pos, dp, teams));
        }
        dp[pos][last+1] = max(dp[pos][last+1], solve(pos+1, last, dp, teams));
        return dp[pos][last+1];
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>>teams;
        int n = ages.size();
        for(int i=0; i<n; i++){
            teams.push_back({ages[i], scores[i]});
        }
        sort(teams.begin(), teams.end());

        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0, -1, dp, teams);
    }
};