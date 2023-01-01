// https://leetcode.com/problems/longest-repeating-substring

struct info
{
    int idx, xx, yy;
    bool operator < (const info &other) const {
        if(xx == other.xx)
            return yy < other.yy;
        return xx < other.xx;
    }
} sa[2005];

class Solution {
public:
    int step;
    int Rank[20][2005], lcp[2005];
    
    void BuildSA(string &s) {
        int n = s.size();
        
        for(int i=0 ; i<n ; i++){
            Rank[0][i] = s[i] - 'a';
        }
        
        step = 1;
        for(int jump=1 ; (jump>>1) < n ; jump <<= 1, step++){
            for(int i=0 ; i<n ; i++){
                sa[i].xx = Rank[step-1][i];
                sa[i].yy = (i + jump) < n ? Rank[step-1][i+jump] : -1;
                sa[i].idx = i;
            }
            
            sort(sa, sa+n);
        
            for(int i=0 ; i<n ; i++){
                Rank[step][sa[i].idx] = (i > 0 && sa[i].xx == sa[i-1].xx && sa[i].yy == sa[i-1].yy) ? Rank[step][sa[i-1].idx] : i;
            }
        }
    }
    
    void BuildLCP(int n) {
        vector<pair<int, int>>temp(n, {0, 0});
        for(int i=0 ; i<n ; i++)
            temp[i] = {Rank[step-1][i], i};
        sort(temp.begin(), temp.end());
        
        for(int i=1 ; i<n ; i++){
            int x = temp[i-1].second, y = temp[i].second;
            // cout<<x<<' '<<y<<' ';
            lcp[i] = 0;
            
            for(int j=step-1 ; j>=0 && x<n && y<n ; j--){
                if(Rank[j][x] == Rank[j][y]){
                    lcp[i] += (1<<j);
                    x += (1<<j);
                    y += (1<<j);
                }
            }
            // cout<<lcp[i]<<endl;
        }
    }
    
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        BuildSA(s);
        BuildLCP(n);
        
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            ans = max(ans, lcp[i]);
        }
        return ans;
    }
};