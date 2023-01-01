// https://leetcode.com/problems/design-hit-counter

class HitCounter {
public:
    unordered_map<int, int>mymap;
    vector<int>t_stamp;
    HitCounter() {
        mymap.clear();
        t_stamp.clear();
    }
    
    void hit(int timestamp) {
        t_stamp.emplace_back(timestamp);
        mymap[timestamp]++;
    }
    
    int getHits(int timestamp) {
        int ans = 0;
        int lidx = lower_bound(t_stamp.begin(), t_stamp.end(), timestamp) - t_stamp.begin();
        if(lidx == t_stamp.size()) lidx--;
       
        for(int i=lidx; i>=0; i--){
            // cout<<i<<' '<<t_stamp[i]<<endl;
            if(timestamp - t_stamp[i] < 300){
                ans += mymap[t_stamp[i]];
            }
            else break;
        }
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */