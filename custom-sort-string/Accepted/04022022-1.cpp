class Solution {
public:
    string customSortString(string y, string x) {
        vector<int>freq(26, 0);
        for(int i=0; i<x.size(); i++){
            freq[x[i]-'a']++;
        }

        string ans = "";
        for(int i=0; i<y.size(); i++){
            for(int j=0; j<freq[y[i]-'a']; j++){
                ans += y[i];
            }
            freq[y[i]-'a'] = 0;
        }

        for(int i=0; i<x.size(); i++){
            if(freq[x[i]-'a'] != 0) ans += x[i];
        }
        // cout<<ans<<endl;

        return ans;
    }
};