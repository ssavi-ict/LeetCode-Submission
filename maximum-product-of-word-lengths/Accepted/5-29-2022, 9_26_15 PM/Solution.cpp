// https://leetcode.com/problems/maximum-product-of-word-lengths

class Solution {
public:
    
    int maskValue[1001];
    int length[1001];
    
    int maxProduct(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            int number = 0;
            for(int j=0; j<words[i].size(); j++){
                int shift = words[i][j] - 'a';
                number = number | (1 << shift);
            }
            length[i] = words[i].size();
            maskValue[i] = number;
        }
        
        int maxVal = 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(!(maskValue[i] & maskValue[j])){
                    maxVal = max(maxVal, length[i]*length[j]);
                }
            }
        }
        return maxVal;
        
    }
};