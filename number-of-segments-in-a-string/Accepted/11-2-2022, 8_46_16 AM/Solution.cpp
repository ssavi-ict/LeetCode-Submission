// https://leetcode.com/problems/number-of-segments-in-a-string

class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        int counter = 0;
        while(ss >> s) counter++;
        return counter;
    }
};