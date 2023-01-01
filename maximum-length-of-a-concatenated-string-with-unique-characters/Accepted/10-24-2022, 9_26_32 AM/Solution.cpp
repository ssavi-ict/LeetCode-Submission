// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution {
public:

    int solve(vector<string> & arr, int pos, string res){
        unordered_set<char>uset(res.begin(), res.end());
        if(uset.size() != res.size()) return 0;
        int ans = res.size();
        for(int i=pos; i<arr.size(); i++){
            ans = max(ans , solve(arr, i+1, res+arr[i]));
        }
        return ans;
    }
    int maxLength(vector<string>& arr) {
        return solve(arr, 0, "");
    }
};