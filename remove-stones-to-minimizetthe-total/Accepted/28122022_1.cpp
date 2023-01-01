class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pileHeap;
        int totalStones = 0, n = piles.size();
        for(int i=0; i<n; i++){
            totalStones += piles[i];
            pileHeap.push(piles[i]);
        }
        while((!pileHeap.empty() && k)){
            int topPile = pileHeap.top();
            pileHeap.pop();
            totalStones -= topPile/2;
            topPile -= (topPile/2);
            if(topPile) pileHeap.push(topPile);
            k--;
        }
        return totalStones;
    }
};