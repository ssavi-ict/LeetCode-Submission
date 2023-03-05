class Solution {
public:

    int compress(vector<char>& chars) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int count = 0, n = chars.size();
        int filled = 0;
        for(int i=0; i<=n; i++){
            if(i == 0 || (i<n && chars[i] == chars[i-1])){
                count++;
            }
            else{
                chars[filled++] = chars[i-1];
                if(count > 1){
                    string digits = to_string(count);
                    for(int j=0; j<digits.size(); j++){
                        chars[filled++] = digits[j];
                    }
                }
                count = 1;
            }
        }
        return filled;
    }
};