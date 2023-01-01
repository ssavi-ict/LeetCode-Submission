// https://leetcode.com/problems/numbers-with-same-consecutive-differences

class Solution {
public:
    
    struct info{
        int number, last_digit, len;
    };
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        
        queue<info>myQ;
        for(int j=1; j<=9; j++){
            myQ.push({j, j, 1});
            while(!myQ.empty()){
                auto top = myQ.front();
                myQ.pop();
                int num = top.number, ldig = top.last_digit, len = top.len;
                if(len == n){
                    ans.push_back(num);
                }
                else{
                    for(int i=0; i<10; i++){
                        int dis = abs(ldig - i);
                        if(dis == k){
                            int newNum = num*10 + i;
                            int newLdig = i;
                            int newLen = len + 1;
                            myQ.push({newNum, newLdig, newLen});
                        }
                    }
                }
            }
        }
        return ans;
    }
};

/*
3, 7
1, 1, 1
1 | 1<3

*/