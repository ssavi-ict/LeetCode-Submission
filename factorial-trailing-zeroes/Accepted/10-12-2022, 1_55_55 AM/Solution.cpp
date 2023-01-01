// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5) return 0;
        int zeroes = 0;
        for(int i=5; i<=n; i += 5){
            int tmp = i;
            while(tmp%5  == 0){
                tmp /= 5;
                zeroes++;
            }
        }
        return zeroes;
    }
};