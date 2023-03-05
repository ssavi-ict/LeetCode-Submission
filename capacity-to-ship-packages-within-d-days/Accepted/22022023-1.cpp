class Solution {
public:

    int isPossible(vector<int> & weights, int mid){
        int dayCount = 0, n = weights.size(), total_weights = 0;
        for(int i=0; i<n; i++){
            if(weights[i] > mid) return INT_MAX;
            total_weights += weights[i];
            if(total_weights > mid) {
                total_weights = weights[i]; 
                dayCount++;
            }
        }
        dayCount++;
        // cout<<mid<<' '<<dayCount<<endl;
        return dayCount;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo = weights[0], hi = accumulate(weights.begin(), weights.end(), 0);
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(isPossible(weights, mid) <= days) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};