// https://leetcode.com/problems/maximum-units-on-a-truck

class Solution {
public:
    
    struct comp{
        bool operator()(pair<int, int>&a , pair<int, int>&b){
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        }
    };
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int, int> >box;
        int n = boxTypes.size();
        for(int i=0; i<n; i++){
            box.push_back(make_pair(boxTypes[i][0], boxTypes[i][1]));
        }
        sort(box.begin(), box.end(), comp());
        int ans = 0;
        for(int i=0; i<n && truckSize; i++){
            if(box[i].first<=truckSize){
                truckSize -= box[i].first;
                ans += (box[i].second * box[i].first);
            }
            else{
                ans += (box[i].second * truckSize);
                truckSize = 0;
            }
        }
        return ans;
    }
};