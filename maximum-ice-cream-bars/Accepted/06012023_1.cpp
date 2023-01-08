class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(costs.begin(), costs.end());
        int i = 0, n = costs.size();
        while(i<n && coins >= costs[i]){
            coins -= costs[i];
            i++;
        }
        return i;
    }
};