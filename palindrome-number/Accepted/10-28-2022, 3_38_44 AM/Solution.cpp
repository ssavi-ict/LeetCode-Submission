// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        int last_digit = x % 10, reversedNumber = 0;
        x /= 10;
        int checkNumber = x, newDivisor = 1;
        while(x >= 10){
            reversedNumber = reversedNumber * 10 + (x % 10);
            x /= 10;
            newDivisor *= 10;
        }
        checkNumber %= newDivisor;
        // cout<<last_digit<<' '<<x<<' '<<checkNumber<<' '<<reversedNumber<<endl;
        return (last_digit == x && checkNumber == reversedNumber) ;
    }
};


// 12321
// lastDigit = 1, x = 1232, check Number = 1232
// reversedNumber = 232, x = 1