class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if(m<n) return {};
        vector<int>P(26,0),S(26,0), ans;
        for( int i = 0;i < n; i++) {P[p[i]-'a']++;S[s[i]-'a']++;}
        if(P==S) ans.push_back(0);
        int startIndex = 0;
        for( int i = n;i < m; i++,startIndex++)
        {
            S[s[startIndex]-'a']--;
            S[s[i]-'a']++;
            if(S==P) ans.push_back(startIndex+1);
        }
        return ans;
        //TC: O(n);
        //SC: O(n) //For storing ans
    }
};