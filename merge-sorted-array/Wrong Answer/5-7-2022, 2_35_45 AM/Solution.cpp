// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lastIdx = m + n - 1;
        m--;
        n--;
        
        while(1) {
            if(m < 0)
                break;
            
            if(n >= 0 && nums1[m] < nums2[n]) {
                nums1[lastIdx--] = nums2[n--];
            }
            else {
                nums1[lastIdx--] = nums1[m--];
            }
        }
    }
};