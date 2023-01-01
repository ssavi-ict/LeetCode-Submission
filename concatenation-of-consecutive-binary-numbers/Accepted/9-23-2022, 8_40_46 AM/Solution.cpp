// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers

class Solution {
public:
    const int M = 1e9 + 7;
    
    int concatenatedBinary(int n) {
        int ans = 0, mul = 1;
        for(int i=n; i>=0; i--){
            int num = i;
            while(num){
                int rem = num & 1; 
                // ans = ((ans % M) + (rem * mul))%M;
                ans = (ans + ((num & 1) ? mul : 0))%M;
                num >>= 1;
                mul <<= 1;
                mul = mul % M;
            }
        }
        return ans;
    }
};