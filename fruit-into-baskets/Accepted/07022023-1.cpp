class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int>fruitType;
        int left = 0, right = 0;
        int ans = 0;
        while(right < n && left <= right){
            auto position = fruitType.find(fruits[right]);
            if(position == fruitType.end() && fruitType.size() == 2){
                while(fruitType.size() != 1){
                    fruitType[fruits[left]]--;
                    if(fruitType[fruits[left]] == 0) fruitType.erase(fruits[left]);
                    left++;
                }
            }
            fruitType[fruits[right]]++;
            right++;
            ans = max(ans, right - left);
        }
        return ans;
    }
};