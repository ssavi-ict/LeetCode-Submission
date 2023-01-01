// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:
    
    bool solve(vector<int>&M, int pos, int count, int curSide, int side){
        if(count == 3) return true;
        for(int i=pos; i<size(M); i++){
            if(M[i] > curSide) continue;
            int stickVal = M[i];
            M[i] = side + 1;
            bool res;
            if(stickVal == curSide){
                res = solve(M, i+1, count+1, side, side);
            }
            else{
                res = solve(M, i+1, count, curSide-stickVal, side);
            }
            if(res) return true;
            M[i] = stickVal;
            while(i<size(M) && M[i+1]==M[i])
                i++;
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = size(matchsticks);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int sum = 0;
        for(int i=0; i<n; i++) sum += matchsticks[i];
        if(sum%4 || matchsticks[0]>sum/4) return false;
        return solve(matchsticks, 0, 0, sum/4, sum/4);
    }
};