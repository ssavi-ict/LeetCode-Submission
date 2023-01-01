// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string n) {
        int sz = n.size();
        int mxV = 0;
        for(int i=0; i<sz; i++){
            mxV = max(mxV, n[i] - '0');
            if(mxV==9) return mxV;
        }
        return mxV;
    }
};