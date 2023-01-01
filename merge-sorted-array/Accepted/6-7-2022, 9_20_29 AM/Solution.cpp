// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp((m+n), 0);
        int i = 0, j = 0, k = 0;
        while(k<m+n){
            if(i>=m){
                temp[k++] = nums2[j++]; continue;
            }
            
            if(j>=n){
                temp[k++] = nums1[i++]; continue;
            }
            temp[k++] = (nums1[i]<=nums2[j])?nums1[i++]:nums2[j++];
            
        }
        for(int i=0; i<m+n; i++){
            nums1[i] = temp[i];
        }
    }
};