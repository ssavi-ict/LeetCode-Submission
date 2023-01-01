// https://leetcode.com/problems/k-th-symbol-in-grammar

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1) return 0;
        return ((__builtin_popcount(k-1) + 1)%2==0);
    }
};