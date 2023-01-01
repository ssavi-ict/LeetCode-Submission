// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game


class Solution {
public:
    
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
   
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(), properties.end(), cmp);
        int max_defense_so_far = 0, ans = 0;
        for(int i=n-1; i>=0; i--){
            if(max_defense_so_far > properties[i][1]) ans++;
            max_defense_so_far = max(max_defense_so_far, properties[i][1]);
        }
        
        return ans;
    }
};