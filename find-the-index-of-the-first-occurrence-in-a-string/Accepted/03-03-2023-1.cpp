class Solution {
public:
    int strStr(string haystack, string needle) {
        int nSize = needle.size(), hSize = haystack.size();
        if(nSize > hSize) return -1;

        vector<long long>powers(hSize, 0);
        const int prime = 31;
        const int mod = 1e9 + 7;
        powers[0] = 1;
        for(int i=1; i<hSize; i++){
            powers[i] = (powers[i-1] * prime) % mod;
        }

        vector<long long>hTable(hSize + 1, 0);
        for(int i=0; i<hSize; i++){
            hTable[i+1] = (hTable[i] + (haystack[i] - 'a' + 1) * powers[i]) % mod;
        }

        long long nHash = 0;
        for(int i=0; i<nSize; i++){
            nHash = ( nHash + (needle[i] - 'a' + 1) * powers[i])%mod;
        }

        for(int i=0; i+nSize-1<hSize; i++){
            long long current_hash = (hTable[i + nSize] - hTable[i] + mod) % mod;
            if(current_hash == (nHash * powers[i])%mod) return i;
        }

        return -1;
    }
};