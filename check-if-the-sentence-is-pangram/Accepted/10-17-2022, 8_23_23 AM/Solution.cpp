// https://leetcode.com/problems/check-if-the-sentence-is-pangram

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int mask = 0;
        for(int i=0; i<sentence.size(); i++){
            int cid = sentence[i] - 'a';
            if(!(mask & (1 << cid))){
                mask |= (1 << cid);
            }
            if(mask == ((1 << 26) - 1)) return true;
        }
        return false;
    }
};