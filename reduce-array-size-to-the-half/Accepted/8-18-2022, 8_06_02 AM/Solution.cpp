// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    unordered_map<int, int>myumap;
    
    int minSetSize(vector<int>& arr) {
        for(int i=0; i<size(arr); i++){
            myumap[arr[i]]++;
        }
        priority_queue<pair<int, int>>PQ;
        for(auto it=myumap.begin(); it!=myumap.end(); ++it){
            int key = it->first, value = it->second;
            PQ.push(make_pair(value, key));
        }
        int cnt = 0, ans = 0;
        while(cnt < arr.size()/2){
            cnt = cnt + PQ.top().first;
            PQ.pop();
            ans++;
        }
        return ans;
    }
};