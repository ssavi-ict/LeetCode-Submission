// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:

    int solve(int pos, int last, vector<pair<int, pair<int, int>>>& myVector, vector<int>&dp){
        if(pos >= myVector.size()) return 0;
        if(myVector[pos].first < last) return solve(pos+1, last, myVector, dp);
        if(dp[pos] != -1) return dp[pos];
        int ans = 0;
        ans = max(solve(pos+1, myVector[pos].second.first, myVector, dp)+myVector[pos].second.second, 
                    solve(pos+1, 0, myVector, dp));
        return dp[pos] = ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int, pair<int, int>>>myVector;
        for(int i=0; i<startTime.size(); i++){
            myVector.push_back(make_pair(startTime[i], make_pair(endTime[i], profit[i])));
        }
        sort(myVector.begin(), myVector.end());
        vector<int>dp(startTime.size()+3, -1);
        return solve(0, 0, myVector, dp);
    }
};