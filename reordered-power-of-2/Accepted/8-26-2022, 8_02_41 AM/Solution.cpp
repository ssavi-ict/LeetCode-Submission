// https://leetcode.com/problems/reordered-power-of-2

class Solution {
public:
    
    vector<int>digit_list(int num){
        vector<int >digits;
        while(num){
            digits.push_back(num%10);
            num /= 10;
        }
        sort(digits.begin(), digits.end());
        return digits;
    }
    
    bool reorderedPowerOf2(int n) {
        vector< vector<int> >powerof2;
        long long val = 1;
        while(val <= 1000000000){
            powerof2.push_back(digit_list(val));
            val = val * 2ll;
        }
        
        vector<int>ndigit = digit_list(n);
        
        for(int i=0; i<powerof2.size(); i++){
            if(powerof2[i] == ndigit){
                return true;
            }
        }
        return false;
    }
};