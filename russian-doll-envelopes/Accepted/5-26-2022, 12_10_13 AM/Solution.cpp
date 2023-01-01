// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    vector<pair<int, int>>env;
    int values[100005];
    
    static bool cmp(pair<int, int>a, pair<int, int>b){
        if(a.first == b.first) return a.second>b.second;
        return a.first < b.first;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int envSz = envelopes.size();
        for(int i=0; i<envSz; i++){
            env.push_back(make_pair(envelopes[i][0], envelopes[i][1]));
        }
        
        sort(env.begin(), env.end(), cmp);
        
        int lisLen = 0, sz = 0;
        
        for(int i=0; i<envSz; i++){
            if(i == 0){
                values[sz] = env[i].second;
                sz++;
            }
            else{
                int index = lower_bound(values, values+sz, env[i].second) - values;
                if(index == sz){
                    values[sz] = env[i].second;
                    lisLen++; sz++;
                }
                else{
                    values[index] = env[i].second;
                }
            }
        }
        return lisLen + 1;
    }
};