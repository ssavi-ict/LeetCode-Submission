// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
public:

    unordered_map<string, vector<int>>umap_key;
    unordered_map<string, vector<string>>umap_value;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap_key[key].push_back(timestamp);
        umap_value[key].push_back(value);
    }
    
    string get(string key, int timestamp) {
        int ub_id = upper_bound(umap_key[key].begin(), umap_key[key].end(), timestamp) - umap_key[key].begin();
        if(ub_id == 0){
            if(umap_key[key][ub_id] > timestamp) return "";
        }
        else ub_id--;
        return umap_value[key][ub_id];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */