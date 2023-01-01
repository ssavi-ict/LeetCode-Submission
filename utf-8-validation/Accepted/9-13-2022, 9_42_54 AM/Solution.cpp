// https://leetcode.com/problems/utf-8-validation

class Solution {
public:
    
    
    bool isSet(int n, int k)
    {
        return (n & (1 << (k - 1)));
    }

    bool FOUR(int a, int b, int c, int d){
        // For 1st
        int cnt = 0;
        if(isSet(a, 8) && isSet(a, 7) && isSet(a, 6) && isSet(a, 5) && !isSet(a, 4)) cnt++;
        if(isSet(b, 8) && !isSet(b, 7)) cnt++;
        if(isSet(c, 8) && !isSet(c, 7)) cnt++;
        if(isSet(d, 8) && !isSet(d, 7)) cnt++;
        return cnt == 4;
    }
    
    bool THREE(int a, int b, int c){
        // For 1st
        int cnt = 0;
        if(isSet(a, 8) && isSet(a, 7) && isSet(a, 6) && !isSet(a, 5)) cnt++;
        if(isSet(b, 8) && !isSet(b, 7)) cnt++;
        if(isSet(c, 8) && !isSet(c, 7)) cnt++;
        return cnt == 3;
    }
    
    bool TWO(int a, int b){
        int cnt = 0;
        if(isSet(a, 8) && isSet(a, 7) && !isSet(a, 6)) cnt++;
        if(isSet(b, 8) && !isSet(b, 7)) cnt++;
        return cnt == 2;
    }
    
    bool ONE(int a){
        // For 1st
        int cnt = 0;
        if(!isSet(a, 8)) cnt++;
        return cnt == 1;
    }
    
    bool validUtf8(vector<int>& data) {
        for(int i=0; i<data.size();){
            if(i+3 <= size(data) - 1 && FOUR(data[i+0], data[i+1], data[i+2], data[i+3])) i+=4 ;
            else if(i+2 <= size(data) - 1 && THREE(data[i+0], data[i+1], data[i+2])) i+=3;
            else if(i+1 <= size(data) - 1 && TWO(data[i+0], data[i+1])) i+=2;
            else if(i <= size(data) - 1 && ONE(data[i])) i+=1;
            else return false;
        }
        return true;
    }
};