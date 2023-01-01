// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mset(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0; i<size(nums); i++){
            if(mset.count(nums[i]-1) == 0){
                int val = nums[i];
                int counter = 1;
                while(mset.count(val + counter)){
                    counter++;
                }
                ans = max(ans, counter);
            }
        }
        return ans;
    }
};

/*int longestConsecutive(vector<int>& nums) {
	unordered_set<int> s(begin(nums), end(nums));
	int longest = 0;
	for(auto& num : s) {
        if(s.count(num - 1)) continue;
		int j = 1;
		while(s.count(num + j)) j++;
		longest = max(longest, j);
	}
	return longest;
}

*/
