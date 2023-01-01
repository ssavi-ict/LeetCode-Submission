// https://leetcode.com/problems/encode-string-with-shortest-length

class Solution {
public:
    string ss;
    int len,occur[155][155];   //occur[i][j] means number of times a pattern(start from ith and its length is j) occur in s[i...n]
    
    string dp[155];
    
    string intToStr(int n)
    {
        string s = "";
        while(n) {
            int digit = n%10;
            s += (digit + '0');
            n /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    
    string FuN(int pos)
    {
        if(pos >= len)
            return "";
        if(dp[pos] != "")
            return dp[pos];
        
        string res = ss.substr(pos, len-pos);
        for(int x=1 ; x <= len-pos ; x++) {
            int nxtPos = pos + (occur[pos][x] * x);
            string temp = intToStr(occur[pos][x]) + "[" + ss.substr(pos, x) + "]" + FuN(nxtPos);
            if(temp.size() < res.size())
                res = temp;
        }
        return dp[pos] = res;
    }
    
    string encode(string s) {
        ss = s;
        len = s.size();
        
        for(int i=0 ; i<len ; i++) {
            for(int j=1 ; j<=len-i ; j++) {
                occur[i][j] = 0;
                string pattern = s.substr(i, j);
                
                for(int spos=i, ppos=0 ; spos < len ; spos++){
                    if(s[spos] != pattern[ppos])
                        break;
                    else
                        ppos++;
                    if(ppos == j){
                        occur[i][j]++;
                        ppos = 0;
                    }
                }
            }
        }
        
        return FuN(0);
    }
};