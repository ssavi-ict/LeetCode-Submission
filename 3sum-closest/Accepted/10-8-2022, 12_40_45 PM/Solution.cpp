// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // -4, -1, 1, 2

        int n = nums.size();
        int ans = -10000001;

        for(int i=0; i<n-2; i++){ // -4
            for(int j=i+1; j<n-1; j++){ // -1, 1, 2
                int lo = j + 1, hi = n - 1;  // 2, 3
                int two_sum = nums[i] + nums[j]; // -5
                int key = target - two_sum;  // 6
                while(lo < hi){
                    int mid = (lo + hi)/2;
                    if(nums[mid] == key) return target; // 1
                    if(key > nums[mid]) lo = mid + 1; // 3
                    else hi = mid - 1;
                }
                if(lo - 1 == j) lo++;
                int value_three = nums[lo-1]; // 1
                if(lo < n){
                    int distance_right = nums[lo] - key; // -4
                    int distance_left = key - nums[lo - 1]; // 6 - 1 = 5
                    if(distance_left > distance_right){
                        value_three = nums[lo];
                    }
                }
                // cout<<nums[i]<<' '<<nums[j]<<' '<<value_three<<endl;
                int sum_three = two_sum + value_three;
                
                if(abs(target - sum_three) < abs(target - ans)){
                    ans = sum_three;
                }
            }
        }
        return ans;
    }
};