// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>occured;
        int n = arr.size();
        for(int i=0; i<n; i++){
            occured[arr[i]]++;
        }

        vector<bool>mapped(n, false);
        for(auto it=occured.begin(); it!=occured.end(); ++it){
            if(mapped[it->second]) return false;
            mapped[it->second] = true;
        }
        return true;
    }
};