// https://leetcode.com/problems/powx-n

class Solution {
public:
    
    double bigpow(double b, int p){
        double ret = 1.0;
        while(p){
            if(p%2) ret = ret * b;
            b = b * b;
            p = p /2;
        }
        return ret;
    }
    
    double myPow(double x, int n) {
        if(n==0 || x == 1.0) return 1.0;
        
        bool needtodiv = false;
        if(n < 0) {
            n = n * -1;
            needtodiv = true;
        }
        
        double ans = bigpow(x, n);
        if(needtodiv) ans = 1/ans;
        return ans;
    }
};