// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
public:

    unordered_map<string, string>umap;
    vector<int>timeValue;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[to_string(timestamp)+key] = value;
        timeValue.push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        int ub_id = upper_bound(timeValue.begin(), timeValue.end(), timestamp) - timeValue.begin();
        if(ub_id == 0) return "";
        ub_id--;
        return umap[to_string(timeValue[ub_id])+key];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */