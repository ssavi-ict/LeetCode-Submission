// https://leetcode.com/problems/largest-number-at-least-twice-of-others

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = 0, secondLargest = 0, largestIndex = -1;
        int n = size(nums);
        for(int i=0; i<n; i++){
            if(nums[i] >= largest){
                secondLargest = largest;
                largest = nums[i];
                largestIndex = i;
            }
            else if(nums[i] >= secondLargest){
                secondLargest = nums[i];
            }
        }
        
        return (secondLargest * 2 <= largest) ? largestIndex : -1;
    }
};