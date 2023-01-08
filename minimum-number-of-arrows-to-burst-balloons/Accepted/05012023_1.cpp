class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& balloons) {
        int n = balloons.size();
        
        sort(balloons.begin(), balloons.end());
        int counter = 0, comp_x = balloons[0][1];
        for(int i=1; i<n; i++){
            if(balloons[i][0] <= comp_x){
                comp_x = min(comp_x, balloons[i][1]);
            }
            else{
                counter++;
                comp_x = balloons[i][1];
            }
        }
        counter++;
        return counter;
    }
};