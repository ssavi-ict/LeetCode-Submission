class Solution {
public:

    bool isOK(string & str, string & pattern){
        int slen = str.size(), plen = pattern.size();
        int i;
        for(i=0; i<slen; i+=plen){
            if(str.substr(i, plen) != pattern) return false;
        }
        return (i == slen);
    }

    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if(m > n){
            swap(str1, str2); swap(m, n);
        }

        int maxLen = 0; string pattern= "";
        for(int i=0; i<m; i++){
            pattern += str2[i];
            if((i+1) == __gcd(m,n) && isOK(str1, pattern) && isOK(str2, pattern)){
                maxLen = max(maxLen, i+1);
            }
        }
        return str2.substr(0, maxLen);
    }
};