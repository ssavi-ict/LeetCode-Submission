// https://leetcode.com/problems/orderly-queue

class Solution {
public:
    
    bool isLexicoGraphicallyLesser(string & a, string & b){
        int n = a.size(), i = 0;
        while(a[i] == b[i]) i++;
        return b[i]<a[i];
    }
    
    string orderlyQueue(string s, int k) {
        if(k>1) sort(s.begin(), s.end());
        else{
            int n = s.size();
            string ans = "";
            for(int i=0; i<n; i++){
                string t = "";
                for(int j=1;j<n; j++){
                    t+=s[j];
                }
                t+=s[0];
                // cout<<s<<' '<<t<<endl;
                if(isLexicoGraphicallyLesser(s, t)){
                    cout<<t<<endl;
                    ans = t;
                }
                s = "";
                s += t;
            }
            return ans;
        }
        return s;
    }
};