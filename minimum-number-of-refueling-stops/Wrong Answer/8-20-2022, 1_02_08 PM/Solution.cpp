// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        priority_queue<int>available;
        int c_fuel = startFuel, c_point = 0, ans = 0;
        stations.push_back({target, 0});
        
        
        for(int i=0; i<stations.size(); i++){
            // cout<<stations.size()<<endl;
            int stop = stations[i][0];  // 10, 20, 30, 60, 100
            int fuel = stations[i][1];  // 60, 30, 30, 40, 0
            
            int to_dist = stop - c_point;  // 10, 20 - 10 = 10, 30 - 20 = 10, 60 - 30 = 30, 100 - 60 = 40
            c_fuel = c_fuel - to_dist; // 0, 0 - 10 = -10, 50 - 10 = 40, 40 - 30 = 10, 10 - 40 = -30
            
            while(!available.empty() && c_fuel<0){
                c_fuel += available.top();  // 10
                available.pop();
                ans++;  // 1 2
            }
            c_point = stop;   // 10, 20, 30, 60, 100
            if(c_point >= target){
                break;
            }
            if(c_fuel < 0) return -1;
            available.push(fuel); // 30, 30
        }
        return ans;
    }
};