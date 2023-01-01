// https://leetcode.com/problems/powx-n

class Solution {
public:
    
    double bigpow(double b, int p){
        if(p==0) return 1.0;
        // cout<<p<<endl;
        double ret = 1.0;
        if(p%2){
            ret = ret * b * bigpow(b, p-1);
        }
        else{
            ret = ret * bigpow(b, p/2) * bigpow(b, p/2);
        }
        // cout<<"R "<<ret<<endl;
        return ret;
    }
    
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        
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