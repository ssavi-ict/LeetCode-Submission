class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(mid & 1){
                if (mid-1 >=0 && nums[mid] == nums[mid - 1]) lo = mid + 1;
                else if(mid + 1 < n && nums[mid] ==  nums[mid + 1]) hi = mid - 1;
                else return nums[mid];
            }
            else{
                if (mid-1 >=0 && nums[mid] == nums[mid - 1]) hi = mid - 1;
                else if(mid + 1 < n && nums[mid] ==  nums[mid + 1]) lo = mid + 1;
                else return nums[mid];
            }
        }
        return nums[lo];
    }
};