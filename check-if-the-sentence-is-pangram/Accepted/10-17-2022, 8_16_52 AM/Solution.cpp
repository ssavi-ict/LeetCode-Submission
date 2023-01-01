// https://leetcode.com/problems/check-if-the-sentence-is-pangram

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int mask = 0, counter = 0;
        int n = sentence.size();
        for(int i=0; i<n; i++){
            int cid = sentence[i] - 'a';
            if(!(mask & (1 << cid))){
                counter++;
                mask |= (1 << cid);
            }
        }
        return counter == 26;
    }
};