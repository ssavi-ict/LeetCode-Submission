// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int>reverseStorage;
        unordered_map<string, int>sameStorage;
        
        for(int i=0; i<n; i++){
            if(words[i][0] - words[i][1] == 0){
                sameStorage[words[i]]++;
            }
            else{
                // string rev = words[i][1] + words[i][0];
                reverseStorage[words[i]]++;
            }
        }
        
        // rev = lc(1), cl(1)
        // same = gg(1)
        
        int returnLength = 0;
        for(auto word = reverseStorage.begin(); word!=reverseStorage.end(); ++word){
            string rev = word->first;
            reverse(rev.begin(), rev.end());
            int originalCount = word->second, reverseCount = reverseStorage[rev];    // 1, 1
            returnLength = returnLength + 4 * min(originalCount, reverseCount);                        // ret = 1
            reverseStorage[word->first] = 0, reverseStorage[rev] = 0;                // lc(0), cl(0)
        }
        // cout<<returnLength<<endl;
        
        int sameSum  = 0;
        bool mid = false;
        for(auto word = sameStorage.begin(); word!=sameStorage.end(); ++word){                                                
            if(word->second % 2 == 0) sameSum = sameSum + word->second;                                
            else{
                sameSum += word->second - 1;
                mid = true;
            }
        }
        if(mid) sameSum++;
        returnLength = returnLength + sameSum * 2;
        
        return returnLength;
    }
    
};