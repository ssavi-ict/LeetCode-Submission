// https://leetcode.com/problems/duplicate-zeros

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> result(arr.size());
        int idx = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0 && idx < arr.size()) {
                result[idx++] = 0;
            }
            if(idx < arr.size())
                result[idx++] = arr[i];
        }
        arr = result;
    }
};