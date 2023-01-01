// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
public:
    unordered_map<int, int>numExist;
    vector<int>nums;
    int index = 0;

    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(numExist.find(val) != numExist.end() && numExist[val] != -1) return false;
        numExist[val] = index;
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(numExist.find(val) == numExist.end() || numExist[val] ==  -1) return false;
        int last = nums.back();
        swap(nums[nums.size()-1], nums[numExist[val]]);
        numExist[last] = numExist[val];
        numExist[val] = -1;
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */