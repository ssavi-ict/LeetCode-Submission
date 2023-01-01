// https://leetcode.com/problems/largest-triangle-area

class Solution {
public:
    double get_distance(int x1, int y1, int x2, int y2){
        double x_dist = (x1 * 1.0) - (x2 * 1.0);
        x_dist *= x_dist;
        double y_dist = (y1 * 1.0) - (y2 * 1.0);
        y_dist *= y_dist;
        double dist = sqrt(x_dist + y_dist);
        return dist;
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        vector<double>distance;
        int n = points.size();
        double ans_area = 0.0, side_a, side_b, side_c, sum, area;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    side_a = get_distance(points[i][0], points[i][1], points[j][0], points[j][1]);
                    side_b = get_distance(points[i][0], points[i][1], points[k][0], points[k][1]);
                    side_c = get_distance(points[j][0], points[j][1], points[k][0], points[k][1]);
                    sum = (side_a + side_b + side_c)/2.0;
                    side_a = sum - side_a;
                    side_b = sum - side_b;
                    side_c = sum - side_c;
                    area = sqrt(sum * side_a * side_b * side_c);
                    ans_area = max(ans_area, area);
                }
            }
        }
        return ans_area;
    }
};