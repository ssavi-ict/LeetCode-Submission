// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:
    struct info{
        int val, idx;
    };
    
    void merge(vector<info>&nums, int L, int M, int R, vector<int>&ans){
        vector<info>ret(R-L+1);
        int l = L, k = 0, r = M+1;
        int small = 0;
        // cout<<"j"<<endl;
        while(l<=M && r<=R){
            if(nums[l].val <= nums[r].val){
                ans[nums[l].idx] += small;
                ret[k] = nums[l];
                k++; l++;
            }
            else{
                small++;
                ret[k] = nums[r];
                r++; k++;
            }
        }
        
        while(l<=M){
            ans[nums[l].idx] += small;
            ret[k] = nums[l];
            k++; l++;
        }
        
        while(r<=R){
            ret[k] = nums[r];
            r++; k++;
        }
        
        l = L; k = 0;
        while(l<=R){
            nums[l++] = ret[k++];
        }
    }
    
    void mergeSort(vector<info>&nums, int start, int end, vector<int>&ans){
        if(start < end){
            int mid = (start + end)/2;
            mergeSort(nums, start, mid, ans);
            mergeSort(nums, mid+1, end, ans);
            merge(nums, start, mid, end, ans);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<info>myvector(size(nums));
        for(int i=0; i<size(nums); i++){
            myvector[i] = {nums[i], i};
        }
        
        vector<int>ans(size(nums), 0);
        mergeSort(myvector, 0, size(nums)-1, ans);
        
        return ans;
    }
};