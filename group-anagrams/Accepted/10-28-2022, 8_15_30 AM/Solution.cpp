// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>umap;
        int n = strs.size();
        for(int i=0; i<n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            umap[s].push_back(strs[i]);
        }

        vector<vector<string>>ans;
        for(auto & it: umap){
            ans.push_back(it.second);
        }
        return ans;
    }
};