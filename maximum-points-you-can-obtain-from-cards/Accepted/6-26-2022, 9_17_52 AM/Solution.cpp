// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        for(int i=1; i<n; i++){
            cardPoints[i] = cardPoints[i-1] + cardPoints[i];
        }
        if(k>=n) return cardPoints[n-1];
        int ans = cardPoints[k-1];
        // cout<<ans<<endl;
        ans = max(ans, cardPoints[n-1]-cardPoints[n-k-1]);
        // cout<<ans<<endl;
        for(int i=0; i<k; i++){
            int front = i, back = k-(i+1);
            ans = max(ans, cardPoints[front]+(cardPoints[n-1] - cardPoints[n-back-1]));
            // cout<<ans<<endl
        }
        return ans;
    }
};