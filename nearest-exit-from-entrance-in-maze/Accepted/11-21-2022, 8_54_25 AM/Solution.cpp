// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
public:

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int steps = 0;

        maze[entrance[0]][entrance[1]] = '+';
        queue<pair<int, int>>mazeQueue;
        mazeQueue.push(make_pair(entrance[0], entrance[1]));
        bool fromEntrance = true;

        while(!mazeQueue.empty()){
            int q_size = mazeQueue.size();
            while(q_size--){
                auto topQcell = mazeQueue.front();
                mazeQueue.pop();
                for(int i=0; i<4; i++){
                    int adj_x = topQcell.first + dx[i];
                    int adj_y = topQcell.second + dy[i];
                    if(adj_x < 0 || adj_y< 0 || adj_x>=m || adj_y>=n){
                        if(fromEntrance) continue;
                        return steps;
                    }
                    if(maze[adj_x][adj_y] == '.'){
                        maze[adj_x][adj_y] = '+';
                        mazeQueue.push(make_pair(adj_x, adj_y));
                    }
                }
                fromEntrance = false;
            }
            steps++;
        }
        return -1;
    }
};