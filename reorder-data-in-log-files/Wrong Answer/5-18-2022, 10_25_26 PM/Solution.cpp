// https://leetcode.com/problems/reorder-data-in-log-files

class Solution {
private:
    static vector<string> getDetails(string a){
        vector<string>output;
        string id = "";
        int pos = 0;
        int n = a.size();
        
        while(a[pos] != ' '){
            id += a[pos++];
        }
        
        while(pos < n && a[pos] == ' ')
            pos++;
        output = {id, a.substr(pos, n - pos)};
        return output;
    }
    
    static bool isNumber(string a){
        if(a[0] >= '0' && a[0] <= '9')
            return true;
        return false;
    }
    
public:
    static bool cmp(string a, string b){
          vector<string>first = getDetails(a);
          vector<string>second = getDetails(b);
          cout<<first[1]<<".."<<isNumber(first[1])<<endl;
        cout<<second[1]<<".."<<isNumber(second[1])<<endl;
        if(!isNumber(first[1]) && !isNumber(second[1])){
            if(first[1] == second[1])
                return first[0] < second[0];
            return first[1] < second[1];
        }
        if(isNumber(first[1]))
            return !isNumber(second[1]);
        
        return true;
        
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};