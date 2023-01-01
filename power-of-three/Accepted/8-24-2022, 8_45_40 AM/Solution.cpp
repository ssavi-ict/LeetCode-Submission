// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double power_double = log10(n*1.0)/log10(3.0);
        return power_double - (int)power_double == 0;
    }
};