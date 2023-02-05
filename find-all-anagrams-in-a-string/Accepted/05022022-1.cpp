class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        vector<int>originalFreq(26, 0), duplicateFreq(26, 0);
        int s1Len = s1.size();
        int s2Len = s2.size();
        if(s1Len > s2Len) return {};

        for(int i=0; i<s1Len; i++){
            originalFreq[s1[i] - 'a']++;
            duplicateFreq[s1[i] - 'a']++;
        }

        vector<int>ans;
        int left = 0, right = 0, tLen = 0;
        while(right<s2Len && left <= right){
            if(duplicateFreq[s2[right]-'a'] > 0){
                duplicateFreq[s2[right]-'a']--;
                right++;
                tLen++;
            }
            else{
                if((right - left) == s1Len){ans.push_back(left);}
                if(left < right && originalFreq[s2[left]-'a'] > 0){
                    duplicateFreq[s2[left]-'a']++;
                    left++; tLen--;
                }
                else{
                    tLen = 0;
                    right++;
                    left = right;
                }
            }
        }
        if((right - left) == s1Len && tLen == s1Len) {ans.push_back(left);}
        return ans;
    }
};