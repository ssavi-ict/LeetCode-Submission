class Solution {
public:

    void getK(int k, vector<int> & kValue){
        while(k){
            kValue.push_back(k % 10);
            k/=10;
        }
        reverse(kValue.begin(),kValue.end());
    }

    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>kValue;
        getK(k, kValue);
        
        int numLen = num.size(), kLen = kValue.size();
        int carry = 0;
        vector<int>ans;

        int i = num.size() - 1, j = kValue.size() - 1;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) sum += num[i];
            if(j >= 0) sum += kValue[j];
            carry = sum / 10;
            ans.push_back(sum % 10);
            i--, j--;
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};