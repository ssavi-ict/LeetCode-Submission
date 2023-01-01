// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int oneCount = 0;
        int zeroCount = 0;
        int ans = INT_MAX;
        
        for(auto num: data){
            oneCount += num;
        }
        
        for(int i = 0; i < data.size(); i++){
            zeroCount += (data[i] == 0);
            if(i >= oneCount)
                zeroCount -= data[i - oneCount] == 0;
            if(i + 1 >= oneCount)
                ans = min(ans, zeroCount);
        }
        
        return ans;
    }
};