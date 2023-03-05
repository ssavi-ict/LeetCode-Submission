class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>>profitCap;
        int n = capital.size();
        for(int i=0; i<n; i++) profitCap.push_back({capital[i], profits[i]});
        sort(profitCap.begin(), profitCap.end());

        int index = 0;
        priority_queue<int>qProfit;
        while(k--){
            while(index < n && profitCap[index].first <= w){
                qProfit.push(profitCap[index++].second);
            }
            if(qProfit.empty()) break;
            w += qProfit.top();
            qProfit.pop();
        }
        return w;
    }
};