// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<string>ret(numRows, "");

        int rowCount = 0;
        for(int i=0; i<n; ){
            while(i<n && rowCount < numRows){
                ret[rowCount].push_back(s[i++]);
                rowCount++;
            }

            rowCount --;
            while(i<n && rowCount){
                rowCount--;
                if(rowCount > 0) ret[rowCount].push_back(s[i++]);
            }
        }

        int index = 0;
        for(int i=0; i<numRows; i++){
            for(int j=0; j<ret[i].size(); j++){
                s[index++] = ret[i][j];
            }
        }
        return s;
    }
};