class Solution {
public:

    bool satisfied(string & s, unordered_map<string, bool> & isFound){

        for(int i=0; i<s.size(); i++){
            string prefix = s.substr(0, i+1);
            string suffix = s.substr(i+1, s.size());
            if(isFound.find(prefix) != isFound.end() && 
              (isFound.find(suffix) != isFound.end() || satisfied(suffix, isFound))){
                  return true;
              }
        }

        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string, bool>isFound;
        int n = words.size();
        for(int i=0; i<n; i++){
            isFound[words[i]] = true;
        }

        vector<string>answerList;
        for(int i=0; i<n; i++){
            if(satisfied(words[i], isFound)){
                answerList.push_back(words[i]);
            }
        }
        return answerList;
    }
};