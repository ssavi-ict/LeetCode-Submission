// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'I'){
                if(i+1<s.size() && (s[i+1]=='V' || s[i+1]=='X')){
                    if(s[i+1] == 'V') num = num + 4;
                    else num = num + 9;
                    i++;
                }
                else{
                    num += 1;
                }
            }
            else if(s[i] == 'C'){
                if(i+1<s.size() && (s[i+1]=='D' || s[i+1]=='M')){
                    if(s[i+1] == 'D') num = num + 400;
                    else num = num + 900;
                    i++;
                }
                else{
                    num += 100;
                }
            }
            else if(s[i] == 'X'){
                if(i+1<s.size() && (s[i+1]=='L' || s[i+1]=='C')){
                    if(s[i+1] == 'L') num = num + 40;
                    else num = num + 90;
                    i++;
                }
                else{
                    num += 10;
                }
            }
            else{
                if(s[i] == 'V') num = num + 5;
                else if(s[i] == 'L') num = num + 50;
                else if(s[i] == 'D') num = num + 500;
                else num = num + 1000;
            }
        }
        return num;
    }
};