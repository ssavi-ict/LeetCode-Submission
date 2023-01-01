// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
private:
    int quickSelect(int l, int r, vector<int>&nums, int k){
        
        
        
        int pivot = (l + random() % (r - l + 1));
        
        swap(nums[pivot], nums[r]);
        int indx = l;
        
        for(int i = l; i < r; i++){
            if(nums[i] < nums[r]){
                swap(nums[i], nums[indx++]);
            }
        }
        
        swap(nums[indx], nums[r]);
        int t = indx - l + 1;
        if(t == k)
            return nums[indx];
        
        if(t > k)
            return quickSelect(l, indx - 1, nums, k);
        
        return quickSelect(indx + 1, r, nums, k - t);
        
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(0, nums.size() - 1, nums, nums.size() - k + 1);
    }
};