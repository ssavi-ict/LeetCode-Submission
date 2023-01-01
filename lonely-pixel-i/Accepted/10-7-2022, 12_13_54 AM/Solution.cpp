// https://leetcode.com/problems/lonely-pixel-i

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture[0].size();
        vector<int>black_row(m+1, 0);
        vector<int>black_column(n+1, 0);
        int ans = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(picture[i][j] == 'B') black_row[i]++;
            }
        }
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                if(picture[i][j] == 'B') black_column[j]++;
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(picture[i][j] == 'B'){
                    if(black_row[i] == 1 && black_column[j] == 1) ans++;
                }
            }
        }

        return ans;
    }
};