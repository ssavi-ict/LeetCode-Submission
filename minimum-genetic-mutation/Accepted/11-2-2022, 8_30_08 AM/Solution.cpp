// https://leetcode.com/problems/minimum-genetic-mutation

class Solution {
public:

    bool distance(string & a, string & b, int len){
        int counter = 0;
        for(int i=0; i<len; i++){
            if(a[i]!=b[i]) counter++;
        }
        return counter == 1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool>visited;
        int steps = 0, bank_size = bank.size();
        queue<string>myQ;
        myQ.push(start);
        visited[start] = true;
        while(!myQ.empty()){
            int sz = myQ.size();
            while(sz--){
                auto top = myQ.front();
                myQ.pop();
                // if(top == end) return steps;
                for(int i=0; i<bank_size; i++){
                    if(!visited[bank[i]] && distance(top, bank[i], 8)){
                        if(bank[i] == end) return steps + 1;
                        visited[bank[i]] = true;
                        myQ.push(bank[i]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};