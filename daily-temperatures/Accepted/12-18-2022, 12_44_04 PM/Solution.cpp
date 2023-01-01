// https://leetcode.com/problems/daily-temperatures

class Solution {
public:

    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>>temp_stack;
        int n = temperatures.size();
        vector<int>ans(n, 0);

        for(int i=0; i<n; i++){
            if(temp_stack.empty()){
                temp_stack.push({i, 0});
            }
            else if(temperatures[temp_stack.top().first] >= temperatures[i]){
                temp_stack.push({i, 0});
            }
            else{
                int count;
                while(!temp_stack.empty() && (temperatures[i] > temperatures[temp_stack.top().first])){
                    auto top_item = temp_stack.top();
                    ans[top_item.first] = top_item.second + 1;
                    temp_stack.pop();
                    if(!temp_stack.empty()){
                        temp_stack.top().second += ans[top_item.first];
                    }
                }
                temp_stack.push({i, 0});
            }
        }
        return ans;
    }
};