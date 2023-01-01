// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    
    const int MOD = 1000000000 + 7;
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>>features;
        for(int i=0; i<n; i++){
            features.emplace_back(make_pair(efficiency[i], speed[i]));
        }
        sort(features.begin(), features.end(), greater<pair<int, int>>());
        
        long long current_ans = 0, current_sum = 0;
        long long current_min, max_ans = 0;
        priority_queue<int>myPQ;
        
        for(int i=0; i<n; i++){
            current_sum += features[i].second;
            myPQ.push(-features[i].second);
            
            if(myPQ.size() > k){
                current_sum -= (-myPQ.top());
                myPQ.pop();
            }
            max_ans = max(max_ans, current_sum * features[i].first);
        }
        return max_ans % MOD;
    }
};

/*
[2,8,2] -> [8,2,2]
[2,7,1] -> [7,2,1]
*/