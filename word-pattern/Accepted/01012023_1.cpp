class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        stringstream ss(s);
        while(ss >> s){
            words.push_back(s);
        }
        int n = pattern.size();
        if(n != words.size()) return false;

        unordered_map<char, string>mymap;
        unordered_map<string, char>checkMap;
        for(int i=0; i<n; i++){
            if(mymap.find(pattern[i]) == mymap.end() && checkMap.find(words[i]) == checkMap.end()){
                mymap[pattern[i]] = words[i];
                checkMap[words[i]] = pattern[i];
            }
            else{
                if((mymap[pattern[i]] != words[i]) || checkMap[words[i]] != pattern[i]) return false;
            }
        }
        return true;
    }
};