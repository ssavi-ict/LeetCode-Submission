class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(tasks.begin(), tasks.end());
        int n = tasks.size(), cnt = 1, total = 0;
        for(int i=0; i<n-1; i++){
            if(tasks[i] == tasks[i+1]){
                cnt++;
            }
            else{
                if(cnt < 2) return -1;
                int remaining = cnt % 3;
                if(remaining == 0) total += (cnt / 3);
                else if(remaining == 2) total += (cnt / 3) + 1;
                else total += (cnt / 3) - 1 + 2;
                cnt = 1;
            }
        }
        if(cnt < 2) return -1;
        int remaining = cnt % 3;
        if(remaining == 0) total += (cnt / 3);
        else if(remaining == 2) total += (cnt / 3) + 1;
        else total += (cnt / 3) - 1 + 2;
        return total;
    }
};