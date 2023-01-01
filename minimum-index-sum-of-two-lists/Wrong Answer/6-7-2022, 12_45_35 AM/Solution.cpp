// https://leetcode.com/problems/minimum-index-sum-of-two-lists

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int ans = INT_MAX;
        vector<string>ret;
        for(int i=0; i<list1.size(); i++){
            for(int j=0; j<list2.size(); j++){
                if(list1[i] == list2[j]){
                    if(ans >= i+j){
                        ans = i + j;
                        ret.push_back(list1[i]);
                    }
                }
            }
        }
        return ret;
    }
};