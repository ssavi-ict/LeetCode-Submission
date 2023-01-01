// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1, end = arr.size() - 2;
        
        int res = 0;
        while(start <= end) {
            int mid = (start + end) >> 1;
            if(arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            }
            else {
                res = mid;
                end = mid - 1;
            }
        }
        return res;
    }
};