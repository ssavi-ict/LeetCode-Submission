// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0; i<size(nums2); i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        int n = size(nums1);
        return n%2?nums1[n/2]:((nums1[n/2-1]+nums1[n/2])*1.0)/2;
    }
};