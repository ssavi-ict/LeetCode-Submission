class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr, vector<int>& brr) {
        unordered_map<int, int>mp;
        int n = arr.size(), m = brr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        vector<int>rest, ans;
        for(int i=0; i<m; i++){
            if(mp.find(brr[i]) != mp.end()){
                for(int j=0; j<mp[brr[i]]; j++){
                    ans.push_back(brr[i]);
                }
                mp[brr[i]] = 0;
            }
        }
        
        for(int i=0; i<n; i++){
            if(mp[arr[i]] != 0) rest.push_back(arr[i]);
        }
        
        sort(rest.begin(), rest.end());
        for(int i=0; i<rest.size(); i++) ans.push_back(rest[i]);
        return ans;
    }
};