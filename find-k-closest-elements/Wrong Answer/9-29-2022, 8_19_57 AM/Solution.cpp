// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int n = arr.size();
        if(lb >= n) lb--;
        
        int left = lb, right = lb;
        vector<int>ans;
        
        while(k--){
            if(left == right){
                ans.push_back(arr[left]);
                left--; right++;
            }
            else if(left <= -1){
                ans.push_back(arr[right++]);
            }
            else if(right >= n){
                ans.push_back(arr[left--]);
            }
            else{
                int left_difference = abs(arr[left] - x);
                int right_difference = abs(arr[right] - x);
                if(left_difference <= right_difference){
                    ans.push_back(arr[left--]);
                }
                else if(left_difference > right_difference){
                    ans.push_back(arr[right++]);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};