// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        
        long left = 2, right = num / 2;
        while(left <= right) {
            long mid = left + (right - left) / 2;
            long guessSquare = mid * mid;
            if(guessSquare == num) {
                return true;
            }
            else if(guessSquare > num) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
        
    }
};