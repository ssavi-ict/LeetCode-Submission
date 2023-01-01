// https://leetcode.com/problems/binary-trees-with-factors

class Solution {
public:
    
    long long dp[1001];
    unordered_map<int, long long>htable;
    const int Mod = 1e9 + 7;
    
    long long solve(int val, vector<int>&arr, int n){
        if(htable.find(val)==htable.end()) return 0;
        if(htable[val]!=-1) return htable[val];
        long long ret = 0;
        for(int i=0; i<n; i++){
            int left = arr[i];
            int right = val/left;
            if(left*right==val && htable.find(right)!=htable.end()){
                // cout<<val<<' '<<left<<' '<<right<<endl;
                long long lVal = solve(left, arr, n);
                long long rVal = solve(right, arr, n);
                ret = (ret + lVal)%Mod;
                ret = (ret + rVal)%Mod;
                ret = (ret + (lVal*rVal)%Mod + 1)%Mod;
            }
        }
        htable[val] = ret;
        return htable[val];
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            htable[arr[i]] = -1;
        }
        
        long long ans = 0;
        for(int i=0; i<n; i++){
            long long ret = solve(arr[i], arr, n);
            ans = (ans + ret + 1)%Mod;
            // cout<<arr[i]<<' '<<ret<<endl;
        }
        return ans;
    }
};