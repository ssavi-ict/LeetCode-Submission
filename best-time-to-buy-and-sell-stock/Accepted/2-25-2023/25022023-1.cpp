class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int minsofar = prices[0];
        int minIdx = 0;
        int n = prices.size(), ans = 0;
        for(int i=1; i<n; i++){
            if(minsofar > prices[i]){
                minIdx = i;
                minsofar = prices[i];
            }
            if(i > minIdx) ans = max(ans, prices[i] - minsofar);
        }
        return ans;
    }
};