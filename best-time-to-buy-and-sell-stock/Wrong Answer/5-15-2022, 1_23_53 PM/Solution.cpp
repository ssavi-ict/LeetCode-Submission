// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar = INT_MAX, maxsofar = INT_MIN;
        int minloc = -1, maxloc = -1;
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
            j--;
            if(minloc < maxloc){
                ans = max(ans, maxsofar - minsofar);
            }
        }
        return ans;
        
    }
};