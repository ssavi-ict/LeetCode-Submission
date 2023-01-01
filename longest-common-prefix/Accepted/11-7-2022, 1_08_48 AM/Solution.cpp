// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = size(strs);
        if(n==1) return strs[0];
        int j = 0;
        while(true){
            for(int i=1; i<n; i++){
                if(j == strs[i-1].size()) return strs[i-1];
                if(j == strs[i].size()) return strs[i];
                if(strs[i][j]!=strs[i-1][j]) return strs[i].substr(0, j);
            }
            j++;
        }
        return "";
    }
};