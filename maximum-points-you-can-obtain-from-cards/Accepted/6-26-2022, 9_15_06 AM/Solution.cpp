// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int cumsum[n+1];
        memset(cumsum, 0, sizeof(cumsum));
        cumsum[0] = cardPoints[0];
        for(int i=1; i<n; i++){
            cumsum[i] = cumsum[i-1] + cardPoints[i];
        }
        if(k>=n) return cumsum[n-1];
        int ans = cumsum[k-1];
        // cout<<ans<<endl;
        ans = max(ans, cumsum[n-1]-cumsum[n-k-1]);
        // cout<<ans<<endl;
        for(int i=0; i<k; i++){
            int front = i, back = k-(i+1);
            ans = max(ans, cumsum[front]+(cumsum[n-1] - cumsum[n-back-1]));
            // cout<<ans<<endl
        }
        return ans;
    }
};