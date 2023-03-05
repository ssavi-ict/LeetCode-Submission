class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        priority_queue<int>numberHeap;
        int minValue = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i] & 1) nums[i] *= 2;
            numberHeap.push(nums[i]);
            minValue = min(minValue, nums[i]);
        }

        int ans = INT_MAX;
        while(!(numberHeap.top()&1)){
            int heapTop = numberHeap.top();
            numberHeap.pop();
            numberHeap.push(heapTop / 2);
            minValue = min(minValue, heapTop / 2);
            heapTop = numberHeap.top();
            ans = min(ans, heapTop - minValue);
        }

        return ans;
    }
};