// https://leetcode.com/problems/daily-temperatures

class Solution {
public:

    struct temp_info{
        int temp, id, count;
    };

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<temp_info>temp_stack;
        int n = temperatures.size();

        for(int i=0; i<n; i++){
            int stored_temp = temperatures[i];
            temperatures[i] = 0;
            if(temp_stack.empty()){
                temp_stack.push({stored_temp, i, 0});
            }
            else if(temp_stack.top().temp >= stored_temp){
                temp_stack.push({stored_temp, i, 0});
            }
            else{
                int count;
                while(!temp_stack.empty() && (stored_temp > temp_stack.top().temp)){
                    auto top_item = temp_stack.top();
                    temperatures[top_item.id] = top_item.count + 1;
                    temp_stack.pop();
                    if(!temp_stack.empty()){
                        temp_stack.top().count += temperatures[top_item.id];
                    }
                }
                temp_stack.push({stored_temp, i, 0});
            }
        }
        return temperatures;
    }
};