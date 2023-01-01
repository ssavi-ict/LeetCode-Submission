// https://leetcode.com/problems/maximum-69-number

class Solution {
public:
    int maximum69Number (int num) {
        vector<int>digits;
        
        while(num){
            digits.push_back(num%10); num /= 10;
        }
        
        reverse(digits.begin(), digits.end());
        
        int ret = 0;
        for(int i=0; i<digits.size(); i++){
            ret = ret * 10 + digits[i];
            if(digits[i] == 6 && num == 0){
                ret = ret + 3; num = 1;
            }
        }
        return ret;
    }
};