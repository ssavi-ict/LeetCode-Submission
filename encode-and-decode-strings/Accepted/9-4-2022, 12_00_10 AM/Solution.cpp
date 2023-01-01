// https://leetcode.com/problems/encode-and-decode-strings

class Codec {
public:

    // Encodes a list of strings to a single string.
    
    string to_str(int n){
        string str = "";
        while(n){
            char c = (n%10) + '0';
            str = c + str;
            n/=10;
        }
        if(str.size()==0) str = "000" + str;
        else if(str.size() == 1) str = "00" + str;
        else if(str.size() == 2) str = "0" + str;
        return str;
    }
    
    string encode(vector<string>& strs) {
        string str = "";
        for(int i=0; i<strs.size(); i++){
            int len = strs[i].size();
            str += to_str(len);
            // cout<<to_str(len)<<endl;
            for(int j=0; j<strs[i].size(); j++){
                str += strs[i][j];
            }    
        }
        // cout<<str<<endl;
        return str;
    }

    // Decodes a single string to a list of strings.
    
    int to_int(string str){
        int n = str.size(), len = 0;
        for(int i=0; i<n; i++){
            len = len*10 + (str[i] - '0');
        }
        return len;
    }
    vector<string> decode(string s) {
        int n = s.size(), start = 0;
        vector<string>ans;
        
        while(start<n){
            int len = to_int(s.substr(start, 3));
            start += 3;
            if(len) ans.push_back(s.substr(start, len));
            else ans.push_back("");
            start += len;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));