// https://leetcode.com/problems/count-items-matching-a-rule

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for(int i=0; i<size(items); i++){
            if(ruleKey == "type" && ruleValue == items[i][0])  ans++;
            else if(ruleKey == "color" && ruleValue == items[i][1]) ans++;
            else if(ruleKey == "name" && ruleValue == items[i][2]) ans++;
        }
        return ans;
    }
};

/*


*/