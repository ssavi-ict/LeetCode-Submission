// https://leetcode.com/problems/similar-rgb-color

class Solution {
public:

    int return_symbol(char ch){
        int ret;
        switch (ch){
            case 'a':
                ret = 10; break;
            case 'b':
                ret = 11; break;
            case 'c': 
                ret = 12; break;
            case 'd':
                ret = 13; break;
            case 'e':
                ret = 14; break;
            case 'f':
                ret = 15; break;
            default:
                ret = (ch - '0');
        }
        return ret;
    }

    int hex2d(string hexval){
        int decimal = 0;
        for(int i=0; i<2; i++){
            decimal *= 16;
            decimal += return_symbol(hexval[i]); 
        }
        return decimal;
    }

    int new_hex2d(char a){
        string new_hex = "";
        new_hex.push_back(a); new_hex.push_back(a);
        return hex2d(new_hex);
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

        vector<char>hexsymbol;
        for(char i='0'; i<='9'; i++) hexsymbol.push_back(i);
        for(char i='a'; i<='f'; i++) hexsymbol.push_back(i);

        int max_sim = INT_MIN;
        string ret = "";
        
        for(int fcode=0; fcode<16; fcode++){
            for(int scode=0; scode<16; scode++){
                for(int tcode=0; tcode<16; tcode++){
                    int first_dd = base_dec[0] - new_hex2d(hexsymbol[fcode]);
                    int second_dd = base_dec[1] - new_hex2d(hexsymbol[scode]);
                    int third_dd = base_dec[2] - new_hex2d(hexsymbol[tcode]);
                    int sum = - (first_dd * first_dd) - (second_dd * second_dd) - (third_dd * third_dd);
                    if(sum > max_sim){
                        max_sim = sum;
                        ret.clear();
                        ret.push_back('#');
                        ret.push_back(hexsymbol[fcode]); ret.push_back(hexsymbol[fcode]);
                        ret.push_back(hexsymbol[scode]); ret.push_back(hexsymbol[scode]);
                        ret.push_back(hexsymbol[tcode]); ret.push_back(hexsymbol[tcode]);
                    }
                }
            }
        }
        return ret;
    }
};