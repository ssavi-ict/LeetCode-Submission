// https://leetcode.com/problems/flatten-2d-vector

class Vector2D {
public:
    vector<int>store;
    int idx = 0;
    
    Vector2D(vector<vector<int>>& vec) {
        for(int i=0; i<size(vec); i++){
            for(int j=0; j<size(vec[i]); j++){
                store.push_back(vec[i][j]);
            }
        }
    }
    
    int next() {
        return store[idx++];
    }
    
    bool hasNext() {
        return idx<size(store);
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */