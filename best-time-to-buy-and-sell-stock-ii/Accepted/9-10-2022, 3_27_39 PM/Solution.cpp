// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_max = prices[0];
        int cur_min = prices[0];
        int ans = 0;
        
        for(int i=0; i<prices.size(); i++){
            if(prices[i] > cur_max){
                cur_max = prices[i];
            }
            else{
                ans += (cur_max - cur_min);
                cur_max = cur_min = prices[i];
            }
        }
        ans += (cur_max - cur_min);
        return ans;
    }
};