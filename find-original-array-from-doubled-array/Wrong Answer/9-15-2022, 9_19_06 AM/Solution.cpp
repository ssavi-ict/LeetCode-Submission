// https://leetcode.com/problems/find-original-array-from-doubled-array

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() & 1) return {};
        int counter[2 * 100005];
        memset(counter, 0, sizeof(counter));
        for(int i=0; i<changed.size(); i++){
            counter[changed[i]]++;
        }
        // sort(changed.begin(), changed.end());
        
        vector<int>ans;
        for(int i=0; i<changed.size(); i++){
            if(changed[i] == 2*changed[i]){
                if(counter[changed[i]] > 1){
                    counter[changed[i]]--;
                    counter[2 * changed[i]]--;
                    ans.push_back(changed[i]);
                }
            }
            else if(counter[changed[i]] && counter[2 * changed[i]]){
                counter[changed[i]]--;
                counter[2 * changed[i]]--;
                ans.push_back(changed[i]);
            }
        }
        if(ans.size() == changed.size()/2)
            return ans;
        return {};
    }
};

//1 2 3 4 6 8