// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

class Solution {
public:
    const int MOD = 1e9 + 7;
    int findMax(vector<int>& horizontalCuts, int h, int hSize){
        int maxH = horizontalCuts[0];
        for(int i=1; i<hSize; i++){
            maxH = max(maxH, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        maxH = max(maxH, h-horizontalCuts[hSize-1]);
        return maxH;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int hSize = horizontalCuts.size(), vSize = verticalCuts.size();
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxH = findMax(horizontalCuts, h, hSize);
        int maxW = findMax(verticalCuts, w, vSize);
        // cout<<maxH<<' '<<maxW<<endl;
        
        long long ans = (long long)maxH % MOD;
        ans = (ans * (long long)maxW%MOD)%MOD;
        
        return ans;
    }
};