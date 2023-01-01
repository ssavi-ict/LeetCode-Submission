// https://leetcode.com/problems/duplicate-zeros

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        
        int possibleDuplicate = 0;
        for(int left = 0; left < len - possibleDuplicate; left++) {
            if(arr[left] == 0) {
                if(left == len - possibleDuplicate - 1) {
                    arr[len-1] = 0;
                    len--;
                    break;
                }
                possibleDuplicate++;
            }
            
        }
        int last = len - possibleDuplicate;
        for(int i = last - 1; i >= 0; i--) {
            if(arr[i] == 0) {
                arr[i+possibleDuplicate] = 0;
                possibleDuplicate--;
            }
            arr[i+possibleDuplicate] = arr[i];
        }
    }
};