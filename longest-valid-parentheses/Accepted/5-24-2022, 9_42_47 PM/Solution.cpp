// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int dp[30005];
    int longestValidParentheses(string s) {
        stack<int>mystack;
        int mxV = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                mystack.push(i);
            }
            else{
                if(!mystack.empty() && s[mystack.top()]=='(' && s[i]==')'){
                    dp[i] = i -mystack.top() + 1;
                    int pidx = i - dp[i];
                    if(pidx < 0) pidx = 0;
                    dp[i] = dp[pidx] + dp[i];
                    mxV = max(mxV, dp[i]);
                    mystack.pop();
                }
            }
        }
        return mxV;
    }
};