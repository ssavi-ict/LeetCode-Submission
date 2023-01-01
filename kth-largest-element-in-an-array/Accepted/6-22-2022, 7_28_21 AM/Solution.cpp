// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        /*
        int n = nums.size();
        bool checked[n];
        memset(checked, false, sizeof(checked));
        int ret_max = -1;
        
        for(int i=0; i<k; i++){
            int mx = 0, loc = -1;
            for(int j=0; j<n; j++){
                if(nums[j] > mx && !checked[j]){
                    mx = nums[j];
                    loc = j;
                }
            }
            checked[loc] = true;
            ret_max = mx;
        }
        return ret_max;
        */
        
        
        int n = nums.size();
        auto list_begin = nums.begin();
        auto list_end = nums.end();
        sort(list_begin, list_end, greater<int>());
        int kth_element = k - 1;
        return nums[kth_element];
        
    }
};