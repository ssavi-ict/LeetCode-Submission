class Solution {
public:
    string addBinary(string a, string b) {
        int n = b.size(), m = a.size();
        if(n > m){
            swap(a, b);
            swap(n, m);
        }
        string zeroes = "";
        for(int i=n; i<m; i++) zeroes += "0";
        b = zeroes + b;
        // cout<<"b "<<b<<endl;
        
        string ans = "";
        bool carry = false;
        for(int i=m-1; i>=0; i--){
            if(a[i] == '0' && b[i] == '0' && carry){
                ans += "1"; carry = false;
            }
            else if(a[i] == '0' && b[i] == '0' && !carry){
                ans += "0"; carry = false;
            }
            else if(a[i] == '0' && b[i] == '1' && carry){
                ans += "0"; carry = true;
            }
            else if(a[i] == '0' && b[i] == '1' && !carry){
                ans += "1"; carry = false;
            }
            else if(a[i] == '1' && b[i] == '0' && carry){
                ans += "0"; carry = true;
            }
            else if(a[i] == '1' && b[i] == '0' && !carry){
                ans += "1"; carry = false;
            }
            else if(a[i] == '1' && b[i] == '1' && carry){
                ans += "1"; carry = true;
            }
            else{
                ans += "0"; carry = true;
            }
        }
        if(carry) ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};