// https://leetcode.com/problems/count-and-say

class Solution {
public:

    string to_str(int n, char dig){
        string say = "";
        while(n){
            int digit = n%10;
            say += (digit + '0');
            n/=10;
        }
        reverse(say.begin(), say.end());
        say.push_back(dig);
        return say;
    }

    string countAndSay(int n) {
        int number = 1;
        string current = "1", ret = "";
        for(int i=2; i<=n; i++){
            int sz = size(current);
            int cnt = 0;
            ret = "";
            for(int j=0; j<sz; j++){
                cnt++;
                if(j+1<sz && current[j] != current[j+1]){
                    ret += to_str(cnt, current[j]);
                    cnt = 0;
                }
            }
            if(cnt > 0){
                ret += to_str(cnt, current[sz-1]);
            }
            current = ret;
        }
        return current;
    }
};