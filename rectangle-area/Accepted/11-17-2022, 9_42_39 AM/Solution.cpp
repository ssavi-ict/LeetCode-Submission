// https://leetcode.com/problems/rectangle-area

class Solution {
public:

    int clashedArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
        if(ax2 < bx1 || ax1 > bx2) return 0;
        if(ay1 > by2 || by1 > ay2) return 0;
        // cout<<1<<endl;
        int orect_x1 = max(ax1, bx1), orect_y1 = min(by2, ay2);
        int orect_x2 = min(ax2, bx2), orect_y2 = max(ay1, by1);
        int dist1_x = abs(orect_x2 - orect_x1);
        int dist1_y = abs(orect_y2 - orect_y1);
        return (dist1_x * dist1_y);
    }

    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rect1_xd = abs(ax2 - ax1);
        int rect1_yd = abs(ay2 - ay1);
        int rect2_xd = abs(bx2 - bx1);
        int rect2_yd = abs(by2 - by1);
        int rect1_area = rect1_xd * rect1_yd;
        int rect2_area = rect2_xd * rect2_yd;
        int total_area = rect1_area + rect2_area;
        if(rect1_area == 0 || rect2_area == 0) return total_area;
        int overlapped = clashedArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        // cout<<"OV "<<overlapped<<endl;
        return total_area - overlapped;
    }
};