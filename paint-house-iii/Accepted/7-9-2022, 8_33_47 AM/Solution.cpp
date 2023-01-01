// https://leetcode.com/problems/paint-house-iii

class Solution {
public:
    int mxVal = 987654321;
    int dp[101][21][101];
    
    int solve(vector<int>&house, vector<vector<int>>& cost, int target, int pos, int pColor, int t_house, int t_color){
        // cout<<pos<<' '<<pColor<<' '<<target<<endl;
        if(pos==t_house && target!=0) return mxVal;
        if(pos!=t_house && target<0) return mxVal;
        if(pos==t_house && target==0) return 0;
        if(dp[pos][pColor][target]!=-1) return dp[pos][pColor][target];
        
        int ret = mxVal;
        if(house[pos]!=0){
            if(house[pos]==pColor){
                ret = min(ret, solve(house, cost, target, pos+1, house[pos], t_house, t_color));
            }
            else{
                ret = min(ret, solve(house, cost, target-1, pos+1, house[pos], t_house, t_color));
            }
        }
        else{
            for(int i=1; i<=t_color; i++){
                if(i==pColor){
                    ret = min(ret, solve(house, cost, target, pos+1, i, t_house, t_color)+cost[pos][i-1]);
                }
                else{
                    ret = min(ret, solve(house, cost, target-1, pos+1, i, t_house, t_color)+cost[pos][i-1]);
                }
            }
        }
        return dp[pos][pColor][target] = ret;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int ret = solve(houses, cost, target, 0, 0, m, n);
        return (ret == mxVal) ? -1 : ret;
    }
};