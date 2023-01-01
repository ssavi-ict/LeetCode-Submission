// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        /*vector<int>perfectSquares;
        for(int i=1; i<=sqrt(n); i++){
            perfectSquares.push_back(i*i);
        }*/

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        queue<int>squareQueue;
        squareQueue.push(n);
        int steps  = 0, qSize, remaining, current;
        while(!squareQueue.empty()){
            qSize = squareQueue.size();
            while(qSize--){
                current = squareQueue.front();
                squareQueue.pop();
                for(int i=sqrt(current); i>=0; i--){
                    if(i*i <= current ){
                        remaining = current - i*i;
                        if(remaining == 0) return steps + 1;
                        squareQueue.push(remaining);
                    }
                }
            }
            steps++;
        }
        return steps;
    }
};