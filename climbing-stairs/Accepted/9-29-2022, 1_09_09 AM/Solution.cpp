// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        int previous_of_current = 1, previous_of_previous = 1, current;
        for(int i=2; i<=n; i++){
            current = previous_of_previous + previous_of_current;
            previous_of_previous = previous_of_current;
            previous_of_current = current;
        }
        return previous_of_current;
    }
};