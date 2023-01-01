// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    
    const int MOD = 1000000000 + 7;
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>>features;
        for(int i=0; i<n; i++){
            features.push_back(make_pair(efficiency[i], speed[i]));
        }
        sort(features.begin(), features.end(), greater<pair<int, int>>());
        
        long long current_ans = 0, current_sum = 0;
        long long current_min;
        priority_queue<int>myPQ;
        for(int i=0; i<n; i++){
            if(myPQ.size() < k){
                current_sum += features[i].second;
                myPQ.push(-features[i].second);
                current_min = features[i].first;
            }
            else {
                int top = -myPQ.top();
                long long temp_sum = current_sum - top + features[i].second;
                long long temp_ans = temp_sum * features[i].first;
                if(temp_ans > current_ans){
                    current_sum = temp_sum;
                    current_min = features[i].first;
                    myPQ.pop();
                    myPQ.push(-features[i].second);
                }
            }
            
            current_ans = current_sum * current_min;
        }
        return current_ans % MOD;
    }
};

/*

[2,10,3,1,5,8] -> [1,5,2,10,3,8]
[5,4,3,9,7,2]  -> [9,7,5,4,3,2]
*/