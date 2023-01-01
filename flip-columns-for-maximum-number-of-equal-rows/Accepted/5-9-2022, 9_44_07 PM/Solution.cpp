// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows

class Solution {
public:
    
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int mx = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<string, int>mymap;
       
        for(int i=0; i<n; i++){
            int cnt = 0; string str, tmp;
            for(int j=0; j<m; j++){
                str.push_back(matrix[i][j]+'0');
                
                if(str[j]=='0') 
                    tmp.push_back('1');
                else 
                    tmp.push_back('0');
            }
            
            mymap[str]++;
            mymap[tmp]++;
        }
        
        for(auto it = mymap.begin(); it!=mymap.end(); ++it){
            mx = max(mx, it->second);
        }
        return mx;
    }
};