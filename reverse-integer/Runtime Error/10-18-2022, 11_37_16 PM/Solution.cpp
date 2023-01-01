// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int sentinel_digits[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        vector<int>new_numbers;
        unsigned int new_x;
        
        if(x < 0){
            sentinel_digits[9] = 8;
            if(x == -2147483648){
                new_x = 2147483648;
            }
            else new_x = -x;
        }
        else{
            new_x = x;
        }

        int ret = 0;
        while(new_x){
            new_numbers.push_back(new_x % 10);
            new_x /= 10;
        }
        if(new_numbers.size() == 10){
            bool flag = true;
            for(int i=0; i<10; i++){
                if(flag && new_numbers[i] > sentinel_digits[i]){
                    return 0;
                }
                flag = false;
                ret = ret * 10 + new_numbers[i];
            }
            if(sentinel_digits[9] == 8) ret = -ret;
            return ret;
        }
        for(int i=0; i<new_numbers.size(); i++){
            ret = ret * 10 + new_numbers[i];
        }
        if(sentinel_digits[9] == 8) ret = -ret;
        return ret;
    }
};