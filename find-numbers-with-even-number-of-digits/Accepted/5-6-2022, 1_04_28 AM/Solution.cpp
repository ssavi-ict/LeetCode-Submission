// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
public:
    int findDigits(int num) {
        int count = 0;
        while(num) {
            count++;
            num /= 10;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(int num: nums) {
            if(findDigits(num) % 2 == 0)
                result++;
        }
        return result;
        
    }
};