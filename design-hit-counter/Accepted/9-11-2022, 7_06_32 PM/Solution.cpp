// https://leetcode.com/problems/design-hit-counter

class HitCounter {
public:
    unordered_map<int, int>mymap;
    HitCounter() {
        mymap.clear();
    }
    
    void hit(int timestamp) {
        mymap[timestamp]++;
    }
    
    int getHits(int timestamp) {
        int ans = 0, cnt = 300;
        while(cnt--){
            if(mymap.find(timestamp)!=mymap.end()){
                ans += mymap[timestamp];
            }
            timestamp--;
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