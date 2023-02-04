class Solution {
public:

    bool isSorted(string & word1, string & word2, unordered_map<char, int> & placement){
        for(int i=0; i<max(word1.size(), word2.size()); i++){
            if(i ==  word1.size() || i == word2.size()) return word1.size() < word2.size();
            else if(placement[word1[i]] < placement[word2[i]]) return true;
            else if(word1[i] == word2[i]) ;
            else return false;
        }
        return true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int>placement;
        for(int i=0; i<26; i++){
            placement[order[i]] = i;
        }

        int n = words.size();
        for(int i=0; i<n-1; i++){
            if(!isSorted(words[i], words[i+1], placement)) { return false;}
        }
        return true;
    }
};