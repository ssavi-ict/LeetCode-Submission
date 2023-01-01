// https://leetcode.com/problems/mirror-reflection

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int h = q;
        while(h < p || h%q!=0){
            h += q;
        }
        
        int vert = h/q;  
        int hori = h/p;
        
        int corner = (hori%2 == 0)? 0 : 1;
        int receptor = (vert%2==0)? 2 : corner;
        return receptor;
    }
};