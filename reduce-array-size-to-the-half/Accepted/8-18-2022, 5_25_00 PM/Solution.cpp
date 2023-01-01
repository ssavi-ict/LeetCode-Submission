// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int cnt_arr[100001], mxstart = 0;
    int fcount[100001];
    
    int minSetSize(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++){
            cnt_arr[arr[i]]++;
            mxstart = max(mxstart, cnt_arr[arr[i]]);
        }
        for(int i=1; i<=100000; i++){
            if(cnt_arr[i]) fcount[cnt_arr[i]]++;
        }

        int ans = 0, cnt = arr.size()/2;
        // cout<<mxstart<<' '<<fcount[mxstart]<<endl;
        for(int i=mxstart; i>=1 && cnt>0; i--){
            if(fcount[i]){
                int times = fcount[i];
                int total_occurance = times * i;
                // cout<<i<<' '<<fcount[i]<<' '<<cnt<<endl;
                if(cnt >= total_occurance){
                    cnt = cnt - total_occurance;
                    ans += times;
                }
                else{
                    // 5 5 5 3 3 3 7 7 7 -> 3 | 2 | 4 | 8
                    int div = (cnt / i) + ((cnt%i==0)?0:1);
                    // cout<<div<<endl;
                    cnt = cnt - (i * div);
                    ans += div;
                }
            }
        }
        return ans;
    }
};