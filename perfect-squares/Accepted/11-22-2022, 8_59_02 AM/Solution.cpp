// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        vector<int>perfectSquares;
        for(int i=1; i<=sqrt(n); i++){
            perfectSquares.push_back(i*i);
        }

        queue<int>squareQueue;
        squareQueue.push(n);
        int steps  = 0;
        while(!squareQueue.empty()){
            int qSize = squareQueue.size();
            while(qSize--){
                auto current = squareQueue.front();
                squareQueue.pop();
                for(int i=perfectSquares.size()-1; i>=0; i--){
                    if(perfectSquares[i] <= current ){
                        int remaining = current - perfectSquares[i];
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