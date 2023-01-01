// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int maxVal = INT_MIN;
        for(int i=0; i<m; i++) maxVal = max(maxVal, nums1[i]);
        for(int i=0; i<n; i++) maxVal = max(maxVal, nums2[i]);
        int mid = m-1, nid = n-1;
        int sz = size(nums1) - 1;
        while(sz >= 0){
            // cout<<mid<<' '<<nid<<endl;
            if(mid<0 || (nid>=0 && nums1[mid]<=nums2[nid])){
                swap(nums1[sz--], nums2[nid--]);
            }
            else{
                swap(nums1[sz--], nums1[mid--]);
            }
        }
    }
};

// 