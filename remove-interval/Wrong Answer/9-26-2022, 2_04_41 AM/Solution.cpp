// https://leetcode.com/problems/remove-interval

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& numbers) {
        int n = intervals.size();
        int a = numbers[0], b = numbers[1];
        numbers.clear();
        
        for(int i=0; i<n; i++){
            numbers.push_back(intervals[i][0]);
            numbers.push_back(intervals[i][1]);
        }
        // 0 2 3 4 5 7
        // 0 5
        // -5 -4 -3 -2 1 2 3 5 8 9
        
        int ub = upper_bound(numbers.begin(), numbers.end(), a) - numbers.begin(); // 1, 1, 4
        int lb = lower_bound(numbers.begin(), numbers.end(), b) - numbers.begin(); // 5, 1, 7
        
        n = numbers.size();  // 6
        intervals.clear();
        
        for(int i=0; i<n; i++){
            if(i==ub){
                while(i < lb){
                    i++;
                }
                if(numbers[i] > b){
                    intervals.push_back({b, numbers[i]});
                }
            }
            else if(i+1 != ub){
                intervals.push_back({numbers[i], numbers[i+1]});
                i++;
            }
            else{
                intervals.push_back({numbers[i], a});
            }
        }
        
        return intervals;
    }
};

/*
-5 -4 -3 -2 1 2 3 5 8 9
-1 -> 4
4 -> 7
*/