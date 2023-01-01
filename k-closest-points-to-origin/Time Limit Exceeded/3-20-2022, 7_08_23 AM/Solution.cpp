// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
private:
    int getDistance(vector<int>a){
        return (a[0] * a[0] + a[1] * a[1]);
    }
    
    void quickSelect(int l, int r, vector<vector<int>>&points, int k){
        int pivot = l + random() % (r - l + 1);
        int indx = l;
        swap(points[r], points[pivot]);
        int pivotDist = getDistance(points[r]);
        
        for(int i = l; i < r; i++){
            int dst1 = getDistance(points[i]);
            if(dst1 < pivotDist){
                swap(points[i], points[indx++]);
            }
        }
        
        swap(points[indx], points[r]);
        
        int cnt = indx - l + 1;
        if(cnt == k)
            return;
        if(k < cnt)
            quickSelect(l, indx - 1, points, k);
        else quickSelect(indx + 1, r, points, k - cnt);
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(0, points.size() - 1, points, k);
        vector<vector<int>>result;
        
        for(int i = 0; i < k; i++){
            result.push_back(points[i]);
        }
        
        return result;
    }
};