// https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    string intToRoman(int num) {
        int numbers[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string romans[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string ans = "";

        while(num){
            for(int i=12; i>=0; i--){
                if(num >= numbers[i]){
                    // cout<<num<<' '<<numbers[i]<<' '<<romans[i]<<endl;
                    ans += romans[i];
                    num -= numbers[i];
                    break;
                }
            }
        }
        return ans;
    }
};