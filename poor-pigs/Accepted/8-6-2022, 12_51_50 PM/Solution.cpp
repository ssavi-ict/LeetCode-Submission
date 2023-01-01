// https://leetcode.com/problems/poor-pigs

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        float v = log10((minutesToTest*1.0)/minutesToDie + 1.0);
        float pp = log10(buckets*1.0);
        // cout<<pp<< ' ' <<v<<endl;
        int pigs =  ceil(pp/v);
        return pigs;
    }
};