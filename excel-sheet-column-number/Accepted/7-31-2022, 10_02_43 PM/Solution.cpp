// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = size(columnTitle);
        long long ans = 0;
        long long mul = 1;
        for(int i=n-2; i>=0; i--){
            mul = mul * 26;
            ans = ans + (mul * (columnTitle[i] - 'A' + 1));
        }
        ans += (columnTitle[n-1] - 'A' + 1);
        return ans;
    }
};