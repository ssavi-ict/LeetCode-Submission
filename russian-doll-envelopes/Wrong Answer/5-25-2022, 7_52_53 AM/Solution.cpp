// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    vector<pair<int, int>>env;
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        for(int i=0; i<envelopes.size(); i++){
            env.push_back(make_pair(envelopes[i][0], envelopes[i][1]));
        }
        sort(env.begin(), env.end());
        int cnt = 0;
        int lastw = 0, lasth = 0;
        for(int i=0; i<env.size(); i++){
            // cout<<env[i].first<<' '<<env[i].second<<endl;
            if(lastw<env[i].first && lasth<env[i].second){
                lastw = env[i].first; lasth = env[i].second;
                cnt++;
            }
        }
        return cnt;
    }
};