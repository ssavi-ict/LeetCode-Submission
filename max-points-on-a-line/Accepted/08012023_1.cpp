class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for(int i=0; i<n; i++){
            unordered_map<double, int>slope_cnt;
            for(int j=i+1; j<n; j++){
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                double slope = x ? (y * 1.0)/(x * 1.0) : INT_MAX * 1.0;
                slope_cnt[slope]++;
                ans = max(ans, slope_cnt[slope]);
            }
        }
        return ans + 1;
    }
};