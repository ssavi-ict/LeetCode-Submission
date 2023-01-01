// https://leetcode.com/problems/maximum-product-of-word-lengths

class Solution {
public:
    
    int maskValue[1001];
    unordered_map<int, int>mask;
    
    int maxProduct(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            int number = 0;
            for(int j=0; j<words[i].size(); j++){
                int shift = words[i][j] - 'a';
                number = number | (1 << shift);
            }
            mask[number] = max(mask[number], (int)words[i].size());
            maskValue[i] = number;
        }
        
        int maxVal = 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(!(maskValue[i] & maskValue[j])){
                    maxVal = max(maxVal, mask[maskValue[i]]*mask[maskValue[j]]);
                }
            }
        }
        return maxVal;
        
    }
};