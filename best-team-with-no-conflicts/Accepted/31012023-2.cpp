class Solution {
public:

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>>teams;
        int n = ages.size();
        for(int i=0; i<n; i++){
            teams.push_back({ages[i], scores[i]});
        }
        sort(teams.begin(), teams.end());

        vector<int>dp(n+1, 0);

        int ans = 0;
        for(int i=0; i<n; i++){
            dp[i] = teams[i].second;
            for(int j=i-1; j>=0; j--){
                if(teams[i].second >= teams[j].second){
                    dp[i] = max(dp[i], teams[i].second + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};