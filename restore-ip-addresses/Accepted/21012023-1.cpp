class Solution {
public:

    int getNumber(string & s){
        int number = 0;
        for(int i=0; i<s.size(); i++){
            number *= 10;
            number += (s[i] - '0');
        }
        return number;
    }

    bool isValidIPAddress(vector<string>&octet, string & s){
        s = "";
        for(int i=0; i<4; i++){
            if(octet[i].size() > 1 && octet[i][0] == '0') return false;
            if(i > 0) s += '.';
            if(getNumber(octet[i]) > 255) return false;
            s += octet[i];
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string>answer;
        int n = s.size();
        if(n < 4 || n > 12) return answer;

        vector<string>octet(4, "");
        for(int i=0; i<n-3 && octet[0].size() <= 3; i++){
            octet[0] += s[i];
            for(int j=i+1; j<n-2 && octet[1].size() <= 3; j++){
                octet[1] += s[j];
                for(int l=j+1; l<n-1 && octet[2].size() <= 3; l++){
                    octet[2] += s[l]; octet[3] = s.substr(l+1, n-(l+1));
                    if(octet[3].size() > 3) continue;
                    string ret = "";
                    if(isValidIPAddress(octet, ret)){
                        answer.push_back(ret);
                    }
                }
                octet[2].clear();
            }
            octet[1].clear();
        }
        return answer;
    }
};