class Solution {
public:
    int countOdds(int low, int high) {
        int first_half = high / 2 + (high % 2);
        low = (low - 1) > 0 ? low - 1: 0;
        int second_half = (low / 2) + (low % 2);
        return first_half-second_half;
    }
};