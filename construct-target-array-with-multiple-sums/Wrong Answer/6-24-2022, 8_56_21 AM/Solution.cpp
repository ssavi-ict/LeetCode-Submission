// https://leetcode.com/problems/construct-target-array-with-multiple-sums

class Solution {
public:
    priority_queue <int, vector<int>, greater<int> >tList, values;
    bool isPossible(vector<int>& target) {
        int n = target.size();
        int cSum = 0, sum = 0;
        for(int i=0; i<n; i++){
            tList.push(target[i]);
            values.push(1);
            cSum++;
            sum += target[i];
        }
        while(cSum<sum){
            int top = values.top();
            int temp = cSum;
            values.pop();
            values.push(cSum);
            cSum = cSum - top + temp;
            // cout<<cSum<<endl;
        }
        if(cSum == sum){
            while(values.size() && tList.size() && values.top() == tList.top()){
                values.pop(); tList.pop();
            }
        }
        return (tList.empty() & values.empty());
    }
};