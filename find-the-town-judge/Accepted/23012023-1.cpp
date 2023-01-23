class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>gainTrust(1001, 0), haveTrust(1001, 0);
        for(int i=0; i<trust.size(); i++){
            gainTrust[trust[i][1]]++;
            haveTrust[trust[i][0]]++;
        }

        for(int i=1; i<1001; i++){
            if(gainTrust[i] == n-1 && haveTrust[i] == 0){
                return i;
            }
        }
        return -1;
    }
};