// https://leetcode.com/problems/prefix-and-suffix-search

class WordFilter {
public:
    unordered_map<string, int>mymap;
    WordFilter(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            string word = "";
            for(int j=words[i].size()-1; j>=0; j--){
                word = words[i][j] + word;
                string tmp = word + '$';
                for(int l=0; l<words[i].size(); l++){
                    tmp = tmp + words[i][l];
                    mymap[tmp] = i;
                }
                
            }
        }
    }
    
    int f(string prefix, string suffix) {
        suffix += "$" + prefix;
        if(mymap.find(suffix)==mymap.end()) return -1;
        return mymap[suffix];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */