// https://leetcode.com/problems/poor-pigs

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log10(buckets*1.0)/log10((minutesToTest*1.0)/minutesToDie + 1.0));
    }
};