class Solution {
public:

    string to_str(int n){
        string s = "";
        while(n){
            s += (n % 10 + '0') ;
            n /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int compress(vector<char>& chars) {
        int count = 0, n = chars.size();
        int filled = 0;
        for(int i=0; i<=n; i++){
            if(i == 0 || (i<n && chars[i] == chars[i-1])){
                count++;
            }
            else{
                chars[filled++] = chars[i-1];
                if(count > 1){
                    string digits = to_str(count);
                    for(int j=0; j<digits.size(); j++){
                        chars[filled++] = digits[j];
                    }
                }
                count = 1;
            }
        }
        while(n > filled){
            chars.pop_back();
            n--;
        }
        return n;
    }
};