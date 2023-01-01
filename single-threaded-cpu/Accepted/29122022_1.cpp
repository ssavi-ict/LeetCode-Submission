class Solution {
public:
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<pair<int, pair<int,int>>>taskList;
        int n = tasks.size();
        for(int i=0; i<n; i++){
            taskList.push_back(make_pair(tasks[i][0], make_pair(tasks[i][1], i)));
        }
        sort(taskList.begin(), taskList.end());
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<> >taskPQ;

        int tid = 0;
        long long cTime = 0;
        // taskPQ.push({taskList[0].second.first, taskList[0].second.second});
        vector<int>ans;
        while(tid < n || !taskPQ.empty()){
            if(taskPQ.empty() && cTime < taskList[tid].first){
                cTime = taskList[tid].first;
            }

            while(tid < n && cTime >= taskList[tid].first){
                taskPQ.push({taskList[tid].second.first, taskList[tid].second.second});
                tid++;
            }

            auto topTask = taskPQ.top();
            taskPQ.pop();
            cTime += topTask.first;
            ans.push_back(topTask.second);
        }
        return ans;
    }
};