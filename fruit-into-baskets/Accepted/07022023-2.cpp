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
                int minIndex = right;
                for(auto it=fruitType.begin(); it!=fruitType.end(); ++it){
                    minIndex = min(it->second, minIndex);
                }
                fruitType.erase(fruits[minIndex]);
                left = minIndex + 1;
            }
            fruitType[fruits[right]] = right;
            right++;
            ans = max(ans, right - left);
        }
        return ans;
    }
};