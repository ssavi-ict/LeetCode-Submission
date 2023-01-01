// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        bool has[1<<k + 1];
        memset(has, false, sizeof(has));
        int n = s.size();
        int count = 1<<k;
        
        for(int i=0; i<n; i++){
            int sum = -1;
            for(int j=i+k-1; j>=i && j<n; j--){
                if(sum == -1) sum = 0;
                sum = sum + (s[j] - '0') * (1 << (i + k - 1 - j ));
            }
            // cout<<i<<' '<<sum<<endl;
            if(sum !=-1 && !has[sum]){
                has[sum] = true; count--;
            }
        }
        return count == 0;
    }
};