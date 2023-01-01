// https://leetcode.com/problems/daily-temperatures

class Solution {
public:

    struct temp_info{
        int temp, id, count;
    };

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<temp_info>temp_stack;
        int n = temperatures.size();
        vector<int>ans(n, 0);

        for(int i=0; i<n; i++){
            if(temp_stack.empty()){
                temp_stack.push({temperatures[i], i, 0});
            }
            else if(temp_stack.top().temp >= temperatures[i]){
                temp_stack.push({temperatures[i], i, 0});
            }
            else{
                int count;
                while(!temp_stack.empty() && (temperatures[i] > temp_stack.top().temp)){
                    auto top_item = temp_stack.top();
                    ans[top_item.id] = top_item.count + 1;
                    temp_stack.pop();
                    if(!temp_stack.empty()){
                        temp_stack.top().count += ans[top_item.id];
                    }
                }
                temp_stack.push({temperatures[i], i, 0});
            }
        }
        return ans;
    }
};