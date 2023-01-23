class Solution {
public:

    bool isPalindrome(string & s, int start, int end){
        int last = end;
        for(int i=start; i < last; i++){
            if(s[i] != s[last]) return false;
            last--;
        }
        return true;
    }

    void solve(int pos, string & s, vector<string> & partition, vector<vector<string>>& ans, int n){
        if(pos == n){
            ans.push_back(partition);
            return;
        }
        for(int i=pos; i<n; i++){
            if(isPalindrome(s, pos, i)){
                partition.push_back(s.substr(pos, i-pos+1));
                solve(i+1, s, partition, ans, n);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>partition;
        vector<vector<string>>ans;
        int n = s.size();
        solve(0, s, partition, ans, n);
        return ans;
    }
};