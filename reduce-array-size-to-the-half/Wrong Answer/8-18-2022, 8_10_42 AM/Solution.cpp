// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    unordered_map<int, int>myumap;
    
    int minSetSize(vector<int>& arr) {
        for(int i=0; i<size(arr); i++){
            myumap[arr[i]]++;
        }
        vector<int>myvector;
        for(auto it=myumap.begin(); it!=myumap.end(); ++it){
            int key = it->first, value = it->second;
            myvector.push_back(value);
        }
        
        int cnt = 0, ans = 0;
        for(int i=myvector.size()-1; i>=0, cnt<arr.size()/2; i--){
            cnt = cnt + myvector[i];
            ans++;
        }
        return ans;
    }
};