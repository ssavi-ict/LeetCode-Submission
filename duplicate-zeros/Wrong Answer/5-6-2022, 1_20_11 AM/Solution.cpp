// https://leetcode.com/problems/duplicate-zeros

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeroCount = 0;
        for(int num: arr)
            zeroCount += num == 0;
        
        for(int i = arr.size() - 1; i >= 0; i--) {
            if(arr[i] == 0) 
                zeroCount--;
            arr[i] = arr[i-zeroCount];
        }
    }
};