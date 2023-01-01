// https://leetcode.com/problems/construct-target-array-with-multiple-sums

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq;
        int n = target.size();
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += target[i];
            pq.push(target[i]);
        }
        
        while(pq.top() != 1){
            sum = sum - pq.top();
            if(sum<=0 || sum>pq.top()) return false;
            int rem = pq.top() % sum;
            if(rem==0 && sum>1) return false;
            pq.pop();
            pq.push(rem);
            sum += rem;
        }
        return true;
    }
};