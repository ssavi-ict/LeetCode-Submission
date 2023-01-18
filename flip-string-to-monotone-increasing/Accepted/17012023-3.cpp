class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int n = s.size();
        // vector<vector<int>>dp(n+1, vector<int>(2, 0));
        int cur_one = 0, cur_zero = 0, next_one = 0, next_zero = 0;

        for(int pos=n-1; pos>=0; pos--){
            for(int last=1; last>=0; last--){
                if(last == 1){
                    cur_one = (s[pos] == '0') + next_one;
                }
                else{
                    cur_zero = (s[pos] == '0') + next_one;
                    cur_zero = min(cur_zero, (s[pos] == '1') + next_zero);
                }
            }
            next_zero = cur_zero;
            next_one = cur_one;
        }
        return next_zero;
    }
};