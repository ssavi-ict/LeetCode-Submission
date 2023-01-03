class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int colSize = strs[0].size(), rowSize = strs.size();
        int cnt = 0;
        for(int i=0; i<colSize; i++){
            for(int j=1; j<rowSize; j++){
                if(strs[j][i] < strs[j-1][i]){
                    cnt++; break;
                }
            }
        }
        return cnt;
    }
};