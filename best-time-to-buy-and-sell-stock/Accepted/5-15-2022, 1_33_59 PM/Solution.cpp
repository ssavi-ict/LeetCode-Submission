// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar = INT_MAX, maxsofar = INT_MIN;
        int minloc = -1, maxloc = -1;
        int mxArr[prices.size() + 1], mnArr[prices.size() + 1];
        for(int i=0; i<prices.size(); i++){
            mxArr[i] = INT_MIN, mnArr[i] = INT_MAX;
        }
        
        int ans = 0;
        for(int i=0; i<prices.size(); i++){
            int j = prices.size() - i - 1;
            if(minsofar > prices[i]){
                minsofar = prices[i];
                minloc = i;
            }
            if(maxsofar < prices[j]){
                maxsofar = prices[j];
                maxloc = j;
            }
            mnArr[i] = minsofar; mxArr[j] = maxsofar;
            j--;
        }
        
        for(int i=0; i<prices.size(); i++){
            ans = max(ans, mxArr[i] - mnArr[i]);
        }
        
        return ans;
        
    }
};