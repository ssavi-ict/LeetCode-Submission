class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, int>umap;
        vector<vector<int>>pairedCount(26, vector<int>(26, 0));
        int n = ideas.size();

        for(int i=0; i<n; i++){
            umap[ideas[i]] ++;
        }

        long long ans = 0;
        for(int j=0; j<n; j++){
            char firstChar = ideas[j][0];
            string newStr = ideas[j];

            for(char i='a'; i<='z'; i++){
                newStr[0] = i;
                if(umap.find(newStr) == umap.end()){
                    pairedCount[firstChar-'a'][i-'a']++;
                    ans += pairedCount[i-'a'][firstChar-'a'];
                }
            }
        }
        return ans * 2;
    }
};