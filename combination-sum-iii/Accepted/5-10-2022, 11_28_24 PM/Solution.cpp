// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    
    vector< vector<int> > ret;
    
    void rec(int number, int count, int k, int sum, int n, vector<int>&tmp){
        if(count == k){
            if(sum == n){
                ret.push_back(tmp);
            }
            return;
        }
        
        if(number > 9) return;
        tmp.push_back(number);
        rec(number + 1, count + 1, k, sum + number, n, tmp);
        tmp.pop_back();
        rec(number+1, count, k, sum, n, tmp);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>tmp;
        rec(1, 0, k, 0, n, tmp);
        return ret;
    }
};