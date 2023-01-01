// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(long long dividend, long long divisor) {  
        
        if(abs(dividend) == abs(divisor)){
            cout<<divisor<<endl;
            int ans = -1;
            if(dividend<0 && divisor<0){
                ans = 1;
            }
            else if(dividend>0 && divisor>0){
                ans = 1;
            }
            return ans;
        }
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend==INT_MIN) return INT_MAX;
            return -dividend;
        }
        // if(dividend == 0 || abs(dividend)<abs(divisor)) return 0;
        
        bool isPos = true;
        if(divisor<0){
            isPos = isPos ^ 1; divisor = abs(divisor);
        }
        if(dividend<0){
            isPos = isPos ^ 1; dividend = abs(dividend);
        }
        // cout<<divisor<<' '<<dividend<<endl;
        int sum = 0;
        while(dividend >= divisor){
            int count = 0;
            while(((long long)divisor<<(long long)(count + 1)) <= (long long)dividend){
                count++;
            }
            sum = sum + (1<<count);
            // cout<<(divisor<<count) << ' '<<count<<endl;
            dividend = (long long)dividend - (long long)(divisor<<count);
            // cout<<sum <<' '<<dividend<<endl;
        }
        
        if(!isPos) return -sum;
        return sum;
    }
};