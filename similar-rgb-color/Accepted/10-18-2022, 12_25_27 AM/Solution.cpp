// https://leetcode.com/problems/similar-rgb-color

class Solution {
public:

    int return_symbol(char ch){
        if(ch >= '0' && ch <= '9') return (ch - '0');
        return (10 + (ch - 'a'));
    }

    int hex2d(string hexval){
        int decimal = 0;
        for(int i=0; i<2; i++){
            decimal *= 16;
            decimal += return_symbol(hexval[i]); 
        }
        return decimal;
    }

    string get_new_string(vector<pair<string, int>> & pair_decimal, int base_value){
        int min_first = INT_MAX;
        string first_pair = "";
        for(int i=0; i<pair_decimal.size(); i++){
            int value = base_value - pair_decimal[i].second;
            value = value * value;
            if(value < min_first){
                first_pair = "";
                first_pair += pair_decimal[i].first;
                min_first = value;
            }
        }
        return first_pair;
    }

    string similarRGB(string color) {
        int n = color.size();
        vector<int>base_dec;

        for(int i=1; i<n; i+=2){
            string base = "";
            base += color[i]; base += color[i+1];
            int decimal = hex2d(base);
            base_dec.push_back(decimal);
        }

        vector<pair<string, int>>pair_decimal;
        for(char i='0'; i<='9'; i++){
            string hexval = {i, i};
            pair_decimal.push_back(make_pair(hexval, hex2d(hexval)));
        }

        for(char i='a'; i<='z'; i++){
            string hexval = {i, i};
            pair_decimal.push_back(make_pair(hexval, hex2d(hexval)));
        }
        
        string ret = "#";
        ret += get_new_string(pair_decimal, base_dec[0]);
        ret += get_new_string(pair_decimal, base_dec[1]);
        ret += get_new_string(pair_decimal, base_dec[2]);
        
        return ret;
    }
};