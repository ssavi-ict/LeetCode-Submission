// https://leetcode.com/problems/duplicate-zeros

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        
        int possibleDuplicate = 0;
        for(int left = 0; left < len; left++) {
            if(arr[left] == 0) {
                possibleDuplicate++;
            }
            
        }
        //int last = len - possibleDuplicate;
        for(int i = len - 1; i >= 0; i--) {
            if(arr[i] == 0) {
                if(i + possibleDuplicate < len)
                    arr[i+possibleDuplicate] = 0;
                possibleDuplicate--;
            }
            if(i + possibleDuplicate < len)
                arr[i+possibleDuplicate] = arr[i];
        }
    }
};