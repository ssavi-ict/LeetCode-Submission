// https://leetcode.com/problems/image-overlap

class Solution {
public:
    bool isValid(int u, int v, int n){
        if(u>=0 && u<n && v>=0 && v<n) return true;
        return false;
    }

    /*int solve(vector<vector<int>>matrix1, vector<vector<int>>matrix2, int shift_x, int shift_y, int n){
        int counter = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int u =  i + shift_x;
                int v = j + shift_y;
                if(isValid(u, v, n) && matrix2[u][v] == 1 && matrix1[i][j] == 1){
                    counter++;
                }
            }
        }
        return counter;
    }*/
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), ans = 0;
        for(int shift_x=-n; shift_x<=n; shift_x++){   // i = 0
            for(int shift_y=-n; shift_y<=n; shift_y++){  // j= 0, 1, 2, 3
                int counter = 0;
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        int u =  i + shift_x;
                        int v = j + shift_y;
                        if(isValid(u, v, n) && img1[u][v] == 1 && img2[i][j] == 1){
                            counter++;
                        }
                    }
                    ans = max(ans, counter);
                }
            }
        }
        return ans;
    }
};