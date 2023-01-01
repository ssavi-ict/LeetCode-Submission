// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
public:
    unordered_map<int, bool>numExist;
    vector<int>nums;
    int index;

    RandomizedSet() {
        index = 0;
    }
    
    bool insert(int val) {
        if(numExist[val]) return false;
        numExist[val] = true;
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!numExist[val]) return false;
        numExist[val] = false;
        return true;
    }
    
    int getRandom() {
        while(index < nums.size() && !numExist[nums[index]]) index++;
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */