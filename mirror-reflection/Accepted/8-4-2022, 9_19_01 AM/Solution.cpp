// https://leetcode.com/problems/mirror-reflection

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int h = q;
        while(h < p || h%p!=0){
            h += q;
        }
        // cout<<h<<endl;
        
        int vert = h/q;  
        int hori = h/p;
        
        int corner = (hori%2==0)? 0 : 1;
        int receptor = (vert%2==0)? 2 : corner;
        return receptor;
    }
};