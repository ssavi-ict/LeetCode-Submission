// https://leetcode.com/problems/orderly-queue

class Solution {
public:
    
    string orderlyQueue(string s, int k) {
        if(k>1) sort(s.begin(), s.end());
        else{
            int n = s.size();
            string ans = s;
            for(int i=0; i<n; i++){
                s = s.substr(1, n-1) + s[0];
                // cout<<s<<' '<<t<<endl;
                if(s[0] < ans[0]){
                    ans = s;
                }
            }
            return ans;
        }
        return s;
    }
};