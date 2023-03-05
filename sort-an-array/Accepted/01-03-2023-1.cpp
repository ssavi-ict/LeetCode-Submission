class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>counter(100005, 0);
        int n = nums.size();
        for(int i=0; i<n; i++){
            counter[nums[i] + 50000]++;
        }

        nums.clear();
        for(int i=0; i<=100000; i++){
            if(counter[i] > 0){
                for(int j=0; j<counter[i]; j++){
                    nums.push_back(i-50000);
                }
            }
        }
        return nums;
    }
};