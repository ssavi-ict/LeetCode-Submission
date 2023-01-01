// https://leetcode.com/problems/guess-number-higher-or-lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n-1, ans;
        while(lo <= hi){
            int mid = lo + ((hi - lo) >> 1);
            int guessValue = guess(mid);
            if(guessValue == 0) return mid;
            else if(guessValue == -1) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};