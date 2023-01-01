// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int bin_power = log(n)/log(2);
        double power = log(n)/log(2);
        if(bin_power*100 != power*100.0){
            if(bin_power%2 == 0) bin_power++;
        }
        return bin_power%2 == 0;
    }
};