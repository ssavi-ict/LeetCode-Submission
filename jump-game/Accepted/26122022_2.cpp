class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool possible[n+1];
        memset(possible, false, sizeof(possible));
        for(int i=n-1; i>=0; i--){
            if(!possible[i]){
                int next = i + nums[i];
                // if(next >= n-1 || possible[next]) possible[i] = true;
                if(next >= n-1){
                    for(int j=i; j<=n-1; j++){
                        // if(possible[j]) break;
                        possible[j] = true;
                    }
                }
                else{
                    for(int j=i; j<next; j++){
                        // if(possible[j]) break;
                        possible[j] = true;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(!possible[i]) return false;
        }
        return true;
    }
};