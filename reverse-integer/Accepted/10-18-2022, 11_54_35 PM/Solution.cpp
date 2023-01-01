// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while(x){
            int remainder = x % 10;
            if(ret > INT_MAX/10 || (ret == INT_MAX/10 && remainder > 7)) return 0;
            if(ret < INT_MIN/10 || (ret == INT_MIN/10 && remainder < -8)) return 0;
            ret = ret * 10 + remainder;
            x /= 10;
        }
        return ret;
    }
};