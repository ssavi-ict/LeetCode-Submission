// https://leetcode.com/problems/encode-string-with-shortest-length

bool cmp(string s1, string s2)
{
    return s1.size() < s2.size();
}

class Solution {
public:
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
    
    string encode(string s) {
        int len = s.size();
        
        vector<string>encoded;
        for(int i=1 ; i<=len ; i++){
            if(len%i)
                continue;
            
            string pattern = s.substr(0, i);
            string s2 = "";
            for(int j=1 ; j<=len/i ; j++)
                s2 += pattern;
            
            if(s2 != s)
                continue;
            
            string encodedS = intToStr(len/i);
            encodedS += "[";
            encodedS += pattern;
            encodedS += "]";
            encoded.push_back(encodedS);
        }
        sort(encoded.begin(), encoded.end(), cmp);
        
        if(encoded.empty() || encoded[0].size() >= len)
            return s;
        return encoded[0];
    }
};