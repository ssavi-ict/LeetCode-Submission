// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len = nums.size();
        int fSum[len+1], bSum[len+1];
        fSum[0] = nums[0], bSum[len-1] = nums[len-1];
        
        int front = (fSum[0] == x)?1:-1;
        int back = (bSum[len-1] == x)?1:-1;
        
        for(int i=1; i<len; i++){
            fSum[i] = fSum[i-1] + nums[i];
            bSum[len-i-1] = bSum[len-i] + nums[len-i-1];
            if (fSum[i] == x) front = i + 1;
            if (bSum[len-i-1] == x) back = i + 1;
        }
        
        int ans = len + 1;
        if (front != -1) ans = min(ans, front);
        if (back != -1) ans = min(ans, back);
        
        for(int i=len-1; i>=0; i--){
            int key = x - bSum[i];
            if(key<=0) break;
            
            int lo = 0, hi = len-1, ret = -1;
            // cout<<key<<endl;
            while(lo<=hi){
                int mid = lo + (hi - lo)/2;
                if(fSum[mid] == key){
                    ret = (mid+1) + (len-i) ;
                    break;
                }
                if(key < fSum[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            // cout<<ret<<endl;
            if(ret!=-1){
                ans = min(ans, ret);
            }
        }
        return ans==len+1?-1:ans;
    }
};