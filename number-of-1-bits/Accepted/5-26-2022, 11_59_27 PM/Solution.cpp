// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for(int i=0; i<32; i++){
            if(n&(1<<i)) cnt++;
        }
        return cnt;
    }
};