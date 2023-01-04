class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int>ucount;
        int n = tasks.size(), total = 0;
        for(int i=0; i<n; i++){
            ucount[tasks[i]]++;
        }

        for(auto it=ucount.begin(); it!=ucount.end(); ++it){
            if(it->second <= 1) return -1;
            int remainder = (it->second) % 3;
            if(remainder == 0 || remainder == 2) total += (it->second / 3) + (remainder != 0);
            else total += ((it->second / 3)  - 1) + 2;
        }
        return total;
    }
};